//
// Created by lixiaoqing on 2022/9/22.
//

#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
        /**
         * 方法1：其实就是计算 [1, n] 中各元素的质因数为 5 的因数个数。
         * 由于只有 5 的倍数才有质因数 5 ，所以可以不用逐个遍历而是只遍历 5 的倍数
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        int count = 0;
//        for (int i = 5; i <= n; i += 5) {
//            int num = i;
//            while (num % 5 == 0) {
//                ++count;
//                num /= 5;
//            }
//        }
//        return count;

        /**
         * 方法2：实际上就是计算1-n之中有多少个5的因数。以130为例：
         * 第一次除以5时得到26，表明存在26个包含 [一] 个因数5的数；
         * 第二次除以5得到5，表明存在5个包含 [二] 个因数5的数(这些数字的一个因数5已经在第一次运算的时候统计了)；
         * 第三次除以5得到1，表明存在1个包含 [三] 个因数5的数(这些数字的两个因数5已经在前两次运算的时候统计了)；
         * 得到从1-n中所有5的因数的个数。
         * 时间复杂度 O(logn) ，空间复杂度 O(1)
         */
        int count = 0;
        while (n) {
            n /= 5;
            count += n;
        }
        return count;

        /**
         * 方法3：直接除以 5 的所有公约数
         * 时间复杂度 O(1) ，空间复杂度 O(1)
         */
//        return n / 5 + n / 25  + n / 125 + n / 625 + n / 3125;
    }
};

int main() {
    std::cout << Solution().trailingZeroes(5) << std::endl;
    std::cout << Solution().trailingZeroes(30) << std::endl;
    return 0;
}

