//
// Created by lixiaoqing on 2022/12/28.
//

#include <iostream>

int main() {

    int *p = new int(10);
    std::cout << *p << std::endl;
    delete p;

    *p = 20;
    std::cout << *p << std::endl;

    return 0;
}