//
// Created by lixiaoqing on 2022/4/7.
//

#include <iostream>

class Solution {
public:
    double Power(double base, int exponent) {
        /**
         * 方法1：暴力解法。时间复杂度O(n)
         */
//        if (base == 0) {
//            return 0;
//        }
//        if (exponent == 0) {
//            return 1;
//        }
//        if (exponent < 0) {
//            base = 1 / base;
//            exponent = -exponent;
//        }
//        double res = 1;
//        while (exponent > 0) {
//            res *= base;
//            --exponent;
//        }
//        return res;

        /**
         * 方法2：非递归的快速幂。时间复杂度O(logn)，空间复杂度O(1)
         */
        if (base == 0) {
            return 0;
        }
        if (exponent < 0) {
            base = 1 / base;
            exponent = -exponent;
        }
        double res = 1;
        while (exponent) {
            if ((exponent & 0x1) == 1) {
                res *= base;
            }
            base *= base;
            exponent >>= 1;
        }
        return res;

        /**
         * 方法3：递归的快速幂。时间复杂度O(logn)，空间复杂度O(logn)
         */
//        if (base == 0) {
//            return 0;
//        }
//        auto res = pow(base, std::abs(exponent));
//        return (exponent >= 0) ? res : 1 / res;
    }

private:
    double pow(double base, int exp) {
        if (exp == 0) {
            return 1;
        }
        auto res = pow(base, exp / 2);
        base = ((exp & 0x1) == 0) ? 1 : base;
        return res * res * base;
    }
};

int main() {
    std::cout << Solution().Power(2, -2) << std::endl;
    return 0;
}