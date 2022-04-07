//
// Created by lixiaoqing on 2022/4/7.
//

#include <iostream>

class Solution {
public:
    int Sum_Solution(int n) {
        /**
         * 方法1：递归，并且利用 || 运算符的短路特性
         */
        n == 0 || (n += Sum_Solution(n - 1));
        return n;

        /**
         * 方法2：递归，并且利用 && 运算符的短路特性
         */
//        n > 0 && (n += Sum_Solution(n - 1));
//        return n;

        /**
         * 方法2：借助数组
         */
//        char arr[n][n + 1];
//        return sizeof(arr) >> 1;

        /**
         * 方法4：移位。虽然这种方法用到了 while 不符合题意，但是思想值得借鉴
         * 1+2+3+...+n = (n^2 + n) / 2 ，关键在于计算 n * n 。
         * 而 n = 2^0 + 2^1 + ... ，比如 7 = 2^2 + 2^1 + 2^0 。
         * 所以 n * n = n * (2^0 + 2^1 + ...)
         *           = n * 2^0 + n * 2^1 + ...
         * 上面这个公式，其实就是循环将 n 向左逻辑移位，并将移位的结果相加
         */
//        return (square(n) + n) >> 1;
    }

private:
    int square(int n) {
        auto res = 0;
        auto ele = n;
        while (n) {
            if (n & 0x1) {
                res += ele;
            }
            n >>= 1;
            ele <<= 1;
        }
        return res;
    }
};

int main() {
    std::cout << Solution().Sum_Solution(10) << std::endl;
    return 0;
}