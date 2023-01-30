//
// Created by lixiaoqing on 2023/1/30.
//

#include <iostream>

class Solution {
public:
    bool isPowerOfFour(int n) {
        /**
         * 方法1：左移运算
         */
//        if (n <= 0) {
//            return false;
//        }
//        long flag = 1;
//        while (flag < std::numeric_limits<int>::max()) {
//            if (n == flag) {
//                return true;
//            }
//            flag <<= 2;
//        }
//        return false;

        /**
         * 方法2：位判断。4的幂满足两个条件：1、是2的幂；2、二进制表示中，从右向左数，1出现在偶数位上。
         */
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;

    }
};

int main() {
    std::cout << Solution().isPowerOfFour(4) << std::endl;
//    std::cout << std::numeric_limits<int>::max() << std::endl;
    return 0;
}