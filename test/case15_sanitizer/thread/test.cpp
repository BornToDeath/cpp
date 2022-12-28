//
// Created by lixiaoqing on 2022/12/28.
//

#include <iostream>
#include <thread>

static int num = 10;

void func1() {
    for (int i = 0; i < 10; ++i) {
        ++num;
        printf("num=%d\n", num);
    }
}

void func2() {
    for (int i = 0; i < 10; ++i) {
        --num;
        printf("num=%d\n", num);
    }
}

int main() {

    std::thread t1(func1);
    std::thread t2(func2);

    t1.join();
    t2.join();

    return 0;
}