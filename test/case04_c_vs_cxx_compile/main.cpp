//
// Created by lixiaoqing on 2022/3/15.
//

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include "IApplication.h"

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
}

int main() {
    start111();
    while (true) {
        std::cout << "主线程休眠中..." << std::endl;
        sleep(5);
    }
    return 0;
}