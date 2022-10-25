//
// Created by lixiaoqing on 2022/10/25.
//

#include <iostream>
#include <memory>
#include <queue>
#include <thread>
#include "RingBuffer.h"

namespace Test {
    void ringBufferTest() {
        auto ringBuffer = std::make_shared<RingBuffer<int>>(10);
        std::cout << ringBuffer->isEmpty() << ", " << ringBuffer->isFull() << std::endl;

//        for (int i = 1; i <= 10; ++i) {
//            ringBuffer->push(i);
//            std::cout << ringBuffer->isEmpty() << ", " << ringBuffer->isFull() << std::endl;
//            std::cout << "tail=" << *ringBuffer->tail() << std::endl;
//        }

        auto produce = [ringBuffer]() {
            for (int i = 1; i <= 1000; ++i) {
                auto res = ringBuffer->push(i);
                printf("[producer] %d, res=%d\n", i, res);
            }
            printf("[producer] over\n");
        };

        auto consume = [ringBuffer]() {
            while (true) {
                if (!ringBuffer->isEmpty()) {
                    printf("[consumer] %d\n", ringBuffer->pop());
                }
            }
            printf("[consumer] over\n");
        };

        std::thread t1(produce);
        std::thread t2(consume);
        t1.join();
        t2.join();
    }
}

int main() {
    Test::ringBufferTest();
    return 0;
}