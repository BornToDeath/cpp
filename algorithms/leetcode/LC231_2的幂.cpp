//
// Created by lixiaoqing on 2023/1/18.
//

#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        /**
         * 方法1：位运算
         */
//        return n > 0 && ((n & (n - 1)) == 0);

        /**
         * 方法2：位运算
         */
//        return n > 0 && ((n & -n) == n);

        /**
         * 方法3：判断是否为 2^30 的约数
         */
        const int BIG = 1 << 30;
        return n > 0 && BIG % n == 0;
    }
};

int main() {
    std::cout << std::boolalpha
              << Solution().isPowerOfTwo(1) << std::endl
              << Solution().isPowerOfTwo(2) << std::endl
              << Solution().isPowerOfTwo(4) << std::endl
              << Solution().isPowerOfTwo(5) << std::endl
              << Solution().isPowerOfTwo(10) << std::endl
              << Solution().isPowerOfTwo(16) << std::endl
              << Solution().isPowerOfTwo(1024) << std::endl
              << Solution().isPowerOfTwo(-1024) << std::endl;
    return 0;
}