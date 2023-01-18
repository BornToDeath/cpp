//
// Created by lixiaoqing on 2023/1/18.
//

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <unistd.h>
#include <functional>
#include <atomic>
#include <semaphore.h>

using namespace std;

/**
 * 方法1：条件变量
 * @return
 */
class FooBar1 {
private:
    int n;
    std::condition_variable cv;
    std::mutex m;
    bool flag = false;

public:
    FooBar1(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&]() { return !flag; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            flag = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&]() { return flag; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            flag = false;
            cv.notify_all();
        }
    }
};

/**
 * 方法2：原子操作
 */
class FooBar2 {
private:
    int n;
    std::atomic<bool> flag{false};

public:
    FooBar2(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            while (flag.load()) {
                std::this_thread::yield();
            }
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();;
            flag.store(true);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            while (!flag.load()) {
                std::this_thread::yield();
            }
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            flag.store(false);
        }
    }
};

/**
 * 方法3：互斥量
 */
class FooBar3 {
private:
    int n;
    std::mutex m1, m2;

public:
    FooBar3(int n) {
        this->n = n;
        m2.lock();
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            // printFoo() outputs "foo". Do not change or remove this line.
            m1.lock();
            printFoo();
            m2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            m2.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            m1.unlock();
        }
    }
};

/**
 * 方法4：信号量
 * 注意：该方法在 macos 上有问题，因为 macos 弃用了 sem_init 和 sem_destroy 方法！
 */
class FooBar4 {
private:
    int n;
    sem_t s1, s2;

public:
    FooBar4(int n) {
        this->n = n;
        sem_init(&s1, 0, 1);
        sem_init(&s2, 0, 0);
    }

    ~FooBar4() {
        sem_destroy(&s1);
        sem_destroy(&s2);
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem_wait(&s1);
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            sem_post(&s2);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem_wait(&s2);
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            sem_post(&s1);
        }
    }
};

int main() {
    setbuf(stdout, nullptr);  // 关闭缓冲，立即输出
    auto foobar = new FooBar4(3);
    for (int i = 0; i < 10; ++i) {
        std::thread t1([foobar] { foobar->foo([] { printf("foo"); }); });
        std::thread t2([foobar] { foobar->bar([] { printf("bar"); }); });
        t1.join();
        t2.join();
        printf("\n");
    }
    delete foobar;
    return 0;
}