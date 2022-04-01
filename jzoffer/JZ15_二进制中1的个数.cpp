//
// Created by lixiaoqing on 2022/4/1.
//

#include <iostream>

class Solution {
public:
    int NumberOf1(int n) {
        /**
         * 方法1：移位
         */
//        int count = 0;
//        for (int i = 0; i < 32; ++i) {
//            if ((n >> i & 0x1) == 1) {
//                ++count;
//            }
//        }
//        return count;

        /**
         * 方法2：n & (n - 1)
         */
        int count = 0;
        while (n != 0) {
            ++count;
            n &= (n - 1);
        }
        return count;
    }
};

int main() {
    int num = -15;
    std::cout << std::bitset<32>(num) << std::endl;
    std::cout << Solution().NumberOf1(num) << std::endl;
}