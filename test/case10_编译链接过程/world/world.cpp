//
// Created by lixiaoqing on 2022/9/15.
//

#include <iostream>
#include "world.h"

void World::aaa(int num) {
    printf("%s\n", __PRETTY_FUNCTION__);
    printf("num=%d\n", num);
}

void World::bbb() {
    printf("%s\n", __PRETTY_FUNCTION__);
}

void World::ccc() {
    printf("%s\n", __PRETTY_FUNCTION__);
}