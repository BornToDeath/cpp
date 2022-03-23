#include <iostream>


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int findNthDigit(int n) {
        /**
         * 方法1：自上而下
         */
//        if (n < 10) {
//            return n;
//        }
//
//        // 记录所在区间的数的位数
//        int k = 1;
//
//        // n减1剔除0，方便计算
//        --n;
//
//        // 此处必须将n转为long型，否则，下面循环中会出现溢出
//        long N = n;
//        long ele;
//        while (N > 0) {
//            ele = N;
//            N -= (long) pow(10, k - 1) * 9 * k;
//            ++k;
//        }
//        --k;
//
//        // 第几个数
//        int index = ele / k;
//
//        // 该数的第几位
//        int offset = ele % k;
//
//        // 计算该数（加上该区间的基数）
//        long num = (long) pow(10, k - 1) + index;
//
//        // 得到当前位的值
//        return std::to_string(num).at(offset) - '0';

        /**
         * 方法2：
         */
        long long num = 1;
        for (int i = 1; i <= 10; i++) {
            num += 9 * i * pow(10, i - 1);
            if (n < num) {
                num -= 9 * i * pow(10, i - 1);
                int idx = pow(10, i - 1) + (n - num) / i;
                int offset = (n - num) % i;
                return std::to_string(idx)[offset] - '0';
            }
        }
        return -1;
    }
};

int main() {
//    std::cout << INT_MAX << std::endl;
    Solution solution;
    std::cout << solution.findNthDigit(1000000000) << std::endl;
    return 0;
}
