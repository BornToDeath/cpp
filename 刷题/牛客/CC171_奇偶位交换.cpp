//
// Created by lixiaoqing on 2022/6/7.
//

#include <iostream>

class Exchange {
public:
    int exchangeOddEven(int x) {
        // 右移：奇数位置0，偶数位右移一位
        int x1 = (x & 0xaaaaaaaa) >> 1;
        // 左移：偶数位置0，奇数位左移一位
        int x2 = (x & 0x55555555) << 1;
        return x1 | x2;
    }
};

int main() {
    std::cout << Exchange().exchangeOddEven(-10) << std::endl;
    return 0;
}