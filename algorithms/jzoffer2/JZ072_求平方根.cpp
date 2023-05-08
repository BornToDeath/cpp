//
// Created by lixiaoqing on 2023/5/8.
//

#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        /*
         * 方法1: 递增
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
//        for (int i = 1; i <= x; ++i) {
//            if (x / i >= i && x / (i + 1) < (i + 1)) {
//                return i;
//            }
//        }
//        return 0;

        /*
         * 方法2: 二分
         * 时间复杂度 O(logn) , 空间复杂度 O(1)
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
//    std::cout << Solution().mySqrt(0) << std::endl;
//    std::cout << Solution().mySqrt(1) << std::endl;
//    std::cout << Solution().mySqrt(4) << std::endl;
//    std::cout << Solution().mySqrt(10) << std::endl;
    std::cout << Solution().mySqrt(INT_MAX) << std::endl;
    return 0;
}