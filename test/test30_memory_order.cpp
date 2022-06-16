//
// Created by lixiaoqing on 2022/6/16.
//

#include <thread>
#include <atomic>
#include <cassert>

std::atomic<int> x{10};
int y = 1;

void test01() {
    auto func1 = []() {
        y = 2;
        x.store(20, std::memory_order_release);
//        x.store(20, std::memory_order_relaxed);
        printf("After store, y=%d\n", y);
    };
    auto func2 = []() {
        while (true) {
            if (x.load(std::memory_order_acquire) == 20) {
                printf("After load, y=%d\n", y);
                assert(y == 2);
                break;
            }
        }
    };
    for (int i = 0; i < 100; ++i) {
        std::thread(func1).join();
        std::thread(func2).join();
        printf("--------------------\n");
    }

}

int main() {
    test01();
    return 0;
}