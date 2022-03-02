//
// Created by lixiaoqing on 2021/12/2.
//

#include <iostream>
#include "B.h"
#include "Config.h"

void B::print() {
    std::cout << std::boolalpha;
    std::cout << Config::flag << std::endl;
}