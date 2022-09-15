//
// Created by lixiaoqing on 2022/6/20.
//

#include <iostream>
#include "hello.h"

//void print() {
//    std::cout << "Hello world." << std::endl;
//}


void A::aaa() {
    printf("%s\n", __PRETTY_FUNCTION__);
}

void A::bbb() {
    printf("%s\n", __PRETTY_FUNCTION__);
}

void A::ccc() {
    printf("%s\n", __PRETTY_FUNCTION__);
}