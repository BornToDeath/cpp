//
// Created by lixiaoqing on 2022/3/15.
//

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "IApplication.h"

void test01(int num) {
    std::cout << __PRETTY_FUNCTION__ << "| num=" << num << std::endl;
}

void test01(const char *text) {
    std::cout << __PRETTY_FUNCTION__ << "| " << text << std::endl;
}

extern "C" {
void start111();
};

void start111() {

#ifdef __cplusplus
    printf("Main|c++\n");
#else
    printf("Main|c\n");
#endif

    IApplication::getSingleton()->start();

    test01(100);
    test01("Hello World");

    std::string str("End");
    std::cout << str << std::endl;
}

int main() {
    start111();
    while (true) {
        std::cout << "主线程休眠中..." << std::endl;
        sleep(5);
    }
    return 0;
}