//
// Created by lixiaoqing on 2022/11/2.
//

#include <iostream>

int main() {

    int a[3]{};
    for (int i : a) {
        std::cout << i << std::endl;
    }

    std::cout << a[3] << std::endl;
    return 0;
}