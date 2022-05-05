//
// Created by lixiaoqing on 2022/5/5.
//

#include <iostream>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param number long长整型
     * @return long长整型
     */
    long long cutRope(long long number) {
        /**
         * 方法1：递归。考虑到有可能会造成栈溢出
         */
//        if (number <= 4) {
//            return number;
//        }
//        return 3 * cutRope(number - 3) % 998244353;

        /**
         * 方法2：循环。利用快速幂方法计算幂
         */
        if (number <= 3) {
            return number - 1;
        }
        long long int res = 1;
        long long int mod = number % 3;
        long long int div = number / 3;
        if (mod == 0) {
            res = power(3, div) % MOD;
        } else if (mod == 1) {
            res = power(3, div - 1) * 4 % MOD;
        } else {
            res = power(3, div) * 2 % MOD;
        }
        return res;
    }

private:
    /**
     * 快速幂来计算幂结果
     * @param num
     * @param power
     * @return
     */
    long long int power(long long int num, long long int power) {
        long long int sum = 1;
        while (power > 0) {
            if (power % 2 == 1) {
                sum = (sum * num) % MOD;
            }
            num = num * num % MOD;
            power /= 2;
        }
        return sum;
    }

private:
    const long int MOD = 998244353;
};

int main() {
    std::cout << Solution().cutRope(5) << std::endl;
    return 0;
}