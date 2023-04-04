//
// Created by lixiaoqing on 2023/4/4.
//

#include <iostream>

class Solution {
public:
    int sumNums(int n) {
        /*
         * 方法1: 递归
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
//        n > 0 && (n += sumNums(n - 1));
//        return n;

        /*
         * 方法2：移位。虽然这种方法用到了 while 不符合题意，但是思想值得借鉴
         * 1+2+3+...+n = (n^2 + n) / 2 ，关键在于计算 n * n 。
         * 时间复杂度 O(logn) , 空间复杂度 O(1)
         */
        return (square(n) + n) >> 1;
    }

private:
    /**
     * 快速幂的思想
     *   n = 2^0 + 2^1 + ... ，比如 7 = 2^2 + 2^1 + 2^0 。
     *   所以 n * n = n * (2^0 + 2^1 + ...) = n * 2^0 + n * 2^1 + ...
     *   其实就是循环将 n 向左逻辑移位，并将移位的结果相加
     * @param n
     * @return
     */
    int square(int n) {
        int ans = 0;
        int base = n;
        while (n) {
            if (n & 0x1) {
                ans += base;
            }
            n >>= 1;
            base <<= 1;
        }
        return ans;
    }
};


int main() {
    std::cout << Solution().sumNums(8) << std::endl;
    return 0;
}
