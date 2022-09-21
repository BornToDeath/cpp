//
// Created by lixiaoqing on 2022/9/14.
//

#include <iostream>
#include "hello.h"
#include "world.h"

int main() {
    printf("%s\n", __PRETTY_FUNCTION__);
    Hello().aaa();
    World().aaa();
    return 0;
}