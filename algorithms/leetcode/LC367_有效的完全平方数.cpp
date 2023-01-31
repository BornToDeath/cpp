//
// Created by lixiaoqing on 2023/1/31.
//

#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        /**
         * 方法：二分查找
         * 时间复杂度 O(logn) ，空间复杂度 O(1)
         */
        int ans = 0;
        for (int i = 1, j = num; i <= j;) {
            auto mid = i + ((j - i) >> 1);
            if (mid <= num / mid) {
                ans = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return ans * ans == num;
    }
};