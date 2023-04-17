//
// Created by lixiaoqing on 2023/4/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int countDigitOne(int n) {
        /*
         * 方法1: https://blog.csdn.net/yi_Afly/article/details/52012593
         * 时间复杂度 O(logn) , 空间复杂度 O(1)
         */
//        int count = 0, round = n;
//        long base = 1;
//        while (round) {
//            auto weight = round % 10;
//            round /= 10;
//            count += round * base;
//            if (weight > 1) {
//                count += base;
//            } else if (weight == 1) {
//                count += (n % base) + 1;
//            }
//            base *= 10;
//        }
//        return count;

        /*
         * 方法2: https://leetcode.cn/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/1n-zheng-shu-zhong-1-chu-xian-de-ci-shu-umaj8/
         * 时间复杂度 O(logn) , 空间复杂度 O(1)
         */
        int ans = 0;
        for (long i = 1; n >= i; i *= 10) {
            ans += (n / (i * 10)) * i + std::min(std::max(n % (i * 10) - i + 1, 0L), i);
        }
        return ans;
    }
};

int main() {
    std::cout << Solution().countDigitOne(14100) << std::endl;
    std::cout << Solution().countDigitOne(1410065408) << std::endl;
    return 0;
}