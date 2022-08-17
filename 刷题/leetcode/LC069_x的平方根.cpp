//
// Created by lixiaoqing on 2022/8/17.
//

#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        /**
         * 方法1：二分查找
         * 时间复杂度 O(logx) ，空间复杂度 O(1)
         */
//        if (x <= 1) {
//            return x;
//        }
//        int i = 0, j = x;
//        while (i <= j) {
//            int mid = i + ((j - i) >> 1);
//            if (mid > x / mid) {
//                j = mid - 1;
//            } else if (mid + 1 <= x / (mid + 1)) {
//                i = mid + 1;
//            } else {
//                return mid;
//            }
//        }
//        return -1;

        /**
         * 方法2：在方法1的基础上进行优化
         */
        int i = 1, j = x, ans = 0;
        while (i <= j) {
            int mid = i + ((j - i) >> 1);
            // 逐渐向右逼近，寻找 mid 的最大值
            if (mid <= x / mid) {
                i = mid + 1;
                ans = mid;
            } else {
                j = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    std::cout << Solution().mySqrt(2) << std::endl;
    std::cout << Solution().mySqrt(10) << std::endl;
    std::cout << Solution().mySqrt(10000000) << std::endl;
    return 0;
}