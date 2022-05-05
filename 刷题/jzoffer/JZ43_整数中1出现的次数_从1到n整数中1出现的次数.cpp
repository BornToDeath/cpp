//
// Created by lixiaoqing on 2022/4/12.
//

#include <iostream>

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        /**
         * 方法1：数学归纳法，参考：参考：https://blog.csdn.net/yi_Afly/article/details/52012593
         * 时间复杂度：O(logn), 以10为底
         */
        int count = 0;
        int base = 1;
        int round = n;
        while (round > 0) {
            int weight = round % 10;
            round /= 10;
            count += round * base;
            if (weight == 1) {
                count += (n % base) + 1;
            } else if (weight > 1) {
                count += base;
            }
            base *= 10;
        }
        return count;

        /**
         * 方法2：暴力统计法，对于 [1, n] 中的每个数字，计算该数字中 1 的个数
         * 时间复杂度：O(nlogn), 以10为底
         */
//        int count = 0;
//        for (int i = 1; i <= n; ++i) {
//            for (int j = i; j > 0; j /= 10) {
//                if (j % 10 == 1) {
//                    ++count;
//                }
//            }
//        }
//        return count;
    }
};

int main() {
    int n = 534;
    std::cout << Solution().NumberOf1Between1AndN_Solution(n) << std::endl;
    return 0;
}