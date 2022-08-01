//
// Created by lixiaoqing on 2022/3/22.
//

/**
 * 结论：
 *   1. 只要主线程不退出，子线程退出也不会导致进程退出。
 *   2. 如果主线程退出，无论子线程是否退出，进程退出。
 */

#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <condition_variable>

static std::mutex mutex;

#define log(format, ...) { printf(format, ##__VA_ARGS__); printf("\n"); }

void test02() {
    auto func = []() {
        while (true) {
            log("子线程2运行中...");
            sleep(1);
        }
    };
    std::thread t1(func);
    t1.detach();
}

void test01() {
    auto func = []() {
        test02();
        int count = 5;
        while (count > 0) {
            --count;
            log("子线程1运行中...");
            sleep(1);
        }
    };
    std::thread t1(func);
    t1.detach();
}

void func_mutex() {
    static long num = 0;
    mutex.lock();
    ++num;
    if (num % 1000000 == 0) {
        log("num=%ld", num);
    }
    mutex.unlock();
}

class A {
public:
    A() : num(new int(10)) {
        log("%s", __PRETTY_FUNCTION__);
    }

    ~A() {
        log("%s", __PRETTY_FUNCTION__);
        delete num;
        num = nullptr;
    }

public:
    int *num{nullptr};
};

static A a;
std::condition_variable cv;
static bool flag = false;

/**
 * 复现问题：主线程退出，全局静态对象析构导致工作线程访问崩溃。
 * 解决方法：保证退出的顺序，先结束工作线程，最后结束主线程。
 */
void test03() {
    log("Outer: num=%d, %p, %p", *a.num, &a, a.num);
    auto loop = []() {
        for (int i = 0; i < 10; ++i) {
            auto func = []() {
                long count = 10000000000;
                while (count-- > 0) {
                    // 这是关键！为了复现崩溃，日志要全部打印，否则全局变量在析构之后，子线程就可能不会访问已经析构的全局变量，就无法复现崩溃
//                    *a.num = 20;
//                    if (count % 50000000 == 0) {
                        log("[%llu] A::num=%d, %p", std::this_thread::get_id(), *a.num, a.num);
//                    }
                }
                log("thread exit");
            };
            std::thread t(func);
            t.detach();
        }
    };
    std::thread t(loop);
    t.detach();
}

void thread_exit() {
    log("thread start");
    std::this_thread::sleep_for(std::chrono::seconds (5));
    log("ready to exit");
//    exit(0);
}

void test04() {
    class A {
    public:
        A() : th(thread_exit) {
            log(__PRETTY_FUNCTION__);
        }

        ~A() {
            log(__PRETTY_FUNCTION__);
            log("before destroy")
            th.join();
            log("After destroy")
        }

    private:
        std::thread th;
    };

    static A a;
}

int main() {
    log("Enter main");
    test03();
    std::this_thread::sleep_for(std::chrono::seconds(1));
//    test01();
//    int count = 10;
//    while (count > 0) {
//        --count;
//        log("主线程休眠中...");
//        sleep(1);
//    }
//    pthread_exit(NULL);
    log("Leave main");
    return 0;
}