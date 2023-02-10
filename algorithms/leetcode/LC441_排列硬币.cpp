//
// Created by lixiaoqing on 2023/2/9.
//

#include <iostream>

class Solution {
public:
    int arrangeCoins(int n) {
        /**
         * 方法1：减法
         * 时间复杂度 O(k) ，空间复杂度 O(1)
         */
//        int k = 0;
//        while (n >= k + 1) {
//            ++k;
//            n -= k;
//        }
//        return k;

        /**
         * 方法2：二分查找
         * 时间复杂度 O(logn) ，空间复杂度 O(1)
         */
//        // i, j 需要声明为 long 类型，避免下面计算 mid 时溢出
//        long i = 1, j = n;
//        while (i < j) {
//            // 此处 i + j + 1 中再 +1 是为了 mid 取值靠右，不会陷入死循环
//            long mid = (i + j + 1) >> 1;
//            if (mid * (mid + 1) / 2 <= n) {
//                i = mid;
//            } else {
//                j = mid - 1;
//            }
//        }
//        return i;

        /**
         * 方法3：数学
         * 时间复杂度 O(1) ，空间复杂度 O(1)
         */
        return ((int) sqrt(8.0 * n + 1) - 1) >> 1;
    }
};

int main() {
    std::cout << Solution().arrangeCoins(9) << std::endl;
    std::cout << Solution().arrangeCoins(10) << std::endl;
    std::cout << Solution().arrangeCoins(11) << std::endl;
    std::cout << Solution().arrangeCoins(2147483647) << std::endl;
    return 0;
}