//
// Created by boss on 2024/3/20.
//

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

int main() {
    // 将标准输出的缓冲区关闭
    setbuf(stdout, nullptr);
    std::mutex mutex;
    std::condition_variable cv;
    std::atomic<bool> flag{true};
    auto runnable1 = [&]() {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [&] { return flag.load(); });
            printf("A");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            flag.store(false);
            cv.notify_all();
        }
    };
    auto runnable2 = [&]() {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex);
            cv.wait(lock, [&] { return !flag.load(); });
            printf("B");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            flag.store(true);
            cv.notify_all();
        }
    };
    std::thread t1(runnable1);
    std::thread t2(runnable2);
    t1.join();
    t2.join();
    return 0;
}