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

int main() {
    test01();
    int count = 10;
    while(count > 0) {
        --count;
        log("主线程休眠中...");
        sleep(1);
    }
    log("主线程退出...");
    return 0;
}