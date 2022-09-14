//
// Created by lixiaoqing on 2022/9/14.
//

#include <iostream>

void create() {
    int* p = new int[100]();
    delete [] p;
}

int main() {
    char buf[1024];
    create();
    printf("end.\n");
    return 0;
}