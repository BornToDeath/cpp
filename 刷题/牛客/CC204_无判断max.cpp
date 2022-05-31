//
// Created by lixiaoqing on 2022/5/31.
//

#include <iostream>

class Max {
public:
    int getMax(int a, int b) {
        /**
         * 方法1：位运算
         */
        return ((a - b) >> 31) == 0 ? a : b;

        /**
         * 方法2：绝对值
         */
//        return (a + b + std::abs(a - b)) / 2;
    }
};

int main() {
    std::cout << Max().getMax(8, 9) << std::endl;
    return 0;
}