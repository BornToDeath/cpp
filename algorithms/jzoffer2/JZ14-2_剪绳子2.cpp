//
// Created by lixiaoqing on 2023/3/10.
//

#include <iostream>

class Solution {
public:
    int cuttingRope(int n) {
        /**
         * 方法1：时间复杂度 O(N) ，其中 N = n / 3，空间复杂度 O(1)
         */
//        if (n <= 3) {
//            return n - 1;
//        }
//        long long ans = 1;
//        int x = n / 3 - 1, y = n % 3;
//        for (int i = 0; i < x; ++i) {
//            ans =  ans * 3 % MOD;
//        }
//        if (y == 0) {
//            return ans * 3 % MOD;
//        } else if (y == 1) {
//            return ans * 4 % MOD;
//        } else {
//            return ans * 3 * 2 % MOD;
//        }

        /**
         * 方法2：快速幂
         * 时间复杂度 O(logN) ，其中 N = n / 3，空间复杂度 O(1)
         */
        if (n <= 3) {
            return n - 1;
        }
        int x = n / 3 - 1, y = n % 3;
        auto ans = power(3, x);
        if (y == 0) {
            return ans * 3 % MOD;
        } else if (y == 1) {
            return ans * 4 % MOD;
        } else {
            return ans * 3 * 2 % MOD;
        }
    }

private:
    // 快速幂
    long long power(long long num, int pow) {
        long long ans = 1;
        while (pow) {
            if ((pow & 1) == 1) {
                ans = ans * num % MOD;
            }
            num = num * num % MOD;
            pow >>= 1;
        }
        return ans;
    }

private:
    const int MOD = 1000000007;
};