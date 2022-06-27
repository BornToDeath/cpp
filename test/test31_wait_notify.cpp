//
// Created by lixiaoqing on 2022/6/27.
//

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

namespace Test {
    void test01() {
        static std::mutex mutex;
        static std::condition_variable cv;
        static int *num = new int(10);
        static bool isStopped = false;
//        num = nullptr;
        auto func1 = []() {
//            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            while (!isStopped) {
                {
                    std::unique_lock<std::mutex> lock(mutex);
                    printf("wait...\n");
                    cv.wait(lock, []() {
                        return num != nullptr;
                    });
                }
                printf("num=%d\n", *num);
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
            }
        };
        std::thread t1(func1);  // 由于 num 不为空，wait 不会阻塞，直接打印 num 的值
        t1.detach();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        printf("set num nullptr\n");
        num = nullptr;
        cv.notify_all();  // num 置为空，此时 wait 阻塞

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        printf("set num not nullptr\n");
        num = new int(20);  // 此时 num 不为空，但是如果没有 notify ，wait 不会解除阻塞
//        cv.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000000));
    }
}

int main() {
    Test::test01();
    return 0;
}