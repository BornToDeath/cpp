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

void test03() {
    log("Outer: %p, %p", &a, a.num);
    auto loop = []() {
        log("After wait");
        for (int i = 0; i < 10; ++i) {
            auto func = []() {
                long count = 100000000;
                while (count-- > 0) {
                    if (count % 50000000 == 0) {
                        log("[%llu] A::num=%d, %p", std::this_thread::get_id(), *a.num, a.num);
                    }
                }
                log("thread exit");
                exit(1);
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
    test04();
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