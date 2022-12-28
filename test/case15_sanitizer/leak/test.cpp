//
// Created by lixiaoqing on 2022/12/28.
//

/**
 * 注意：Mac 下使用 AppleClang 编译器不支持 leak sanitizer ！
 */

#include <iostream>

int main() {
    int *p = new int(10);
    std::cout << *p << std::endl;
    return 0;
}