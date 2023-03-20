//
// Created by lixiaoqing on 2023/3/20.
//

#include <iostream>

class Solution {
public:
    int findNthDigit(int n) {
        /**
         * 方法1：
         */
//        if (n == 0) {
//            return 0;
//        }
//        long long num = 1;
//        for (int i = 1; i <= 10; ++i) {  // i 表示所在区间的数的位数
//            long long len = pow(10, i - 1) * 9 * i;  // 区间的长度
//            num += len;
//            if (n < num) {
//                num -= len;
//                // 计算这个数
//                int k = (int) pow(10, i - 1) + (n - num) / i;
//                // 该数的第几位
//                int pos = (n - num) % i;
//                return std::to_string(k).at(pos) - '0';
//            }
//        }
//        return -1;

        /**
         * 方法2
         */
        int d = 1;      // 表示目标是几位数
        int count = 9;  // 区间的长度
        while (n > count) {
            n -= d * count;
            ++d;
            count *= 10;
        }
        int start = (int) pow(10, d - 1);  // 区间第一个数
        int num = start + (n - 1) / d;                 // 该数
        return std::to_string(num).at((n - 1) % d) - '0';
    }
};

int main() {
    // 0123456789101112131415161718192021222324252627282930
    std::cout << Solution().findNthDigit(16) << std::endl;
    return 0;
}