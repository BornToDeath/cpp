//
// Created by lixiaoqing on 2021/11/16.
//

#include <iostream>
#include <thread>
#include <mutex>

void test01();

void test02();

int main() {
    test02();
    return 0;
}

void test01() {
    std::cout << std::boolalpha;
    std::thread t1([]() {
        std::cout << "Thread1 正在执行" << std::endl;
    });
    std::cout << t1.joinable() << std::endl;
    t1.detach();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    if (t1.joinable()) {
        std::cout << "joinable=true" << std::endl;
    } else {
        std::cout << "joinable=false" << std::endl;
    }

    // 线程ID
    std::cout << "[1]TID=" << std::this_thread::get_id() << std::endl;  // 16进制
    printf("[2]TID=%llu\n", std::this_thread::get_id());  // 10进制

    // 获取硬件支持的线程并发数
    std::cout << "线程并发数=" << std::thread::hardware_concurrency() << std::endl;
}

static std::mutex mutex;
static std::condition_variable condition;
static int count = 0;

/**
 * 经验证：只有 notify 了，处于 wait 状态的线程才会被唤醒
 */
void test02() {
    auto runnable = []() {
        while (true) {
            {
                std::unique_lock<std::mutex> lock(mutex);
                ++count;
                printf("count=%d\n", count);
                condition.notify_all();
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    };
    std::thread t1(runnable);
    t1.detach();

    auto runnable2 = []() {
        while (true) {
            {
                std::unique_lock<std::mutex> lock(mutex);
                condition.wait(lock);
//                condition.wait(lock, []() {
//                    return (count % 5 == 0);
//                });
                printf(">>> count=%d\n", count);
            }
//            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    };

    std::thread t2(runnable2);
    t2.join();
}