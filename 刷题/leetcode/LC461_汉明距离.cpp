//
// Created by lixiaoqing on 2022/6/29.
//

#include <iostream>
#include <bitset>

class Solution {
public:
    int hammingDistance(int x, int y) {
        /**
         * 方法1：先异或再逐位判断
         */
//        x ^= y;
//        y = 0;
//        while (x) {
//            y += x & 1;
//            x >>= 1;
//        }
//        return y;

        /**
         * 方法2：
         */
//        x ^= y;
//        y = 0;
//        while (x) {
//            ++y;
//            x &= x - 1;
//        }
//        return y;

        /**
         * 方法3：内置函数
         */
        return __builtin_popcount(x ^ y);
    }
};

int main() {
    int x = 3;
    int y = 1;
    std::cout << std::bitset<8>(x) << std::endl;
    std::cout << std::bitset<8>(y) << std::endl;
    std::cout << std::bitset<8>(x ^ y) << std::endl;
    std::cout << Solution().hammingDistance(x, y) << std::endl;
    return 0;
}