//
// Created by lixiaoqing on 2022/8/16.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int divide(int dividend, int divisor) {
        /**
         * 方法1：由于负数的范围更大，所以先将除数和被除数都转换为负数，然后用快速除实现除法
         * 时间复杂度 O((logn)^2) ，空间复杂度 O(1)
         * 参考：https://leetcode.cn/problems/divide-two-integers/solution/liang-shu-xiang-chu-by-leetcode-solution-5hic/
         */
        // 处理特殊情况
        if (divisor == 1) {
            return dividend;
        } else if (divisor == -1) {
            if (dividend == std::numeric_limits<int>::min()) {
                return std::numeric_limits<int>::max();
            } else {
                return -dividend;
            }
        }
        // 转为负数，因为负数的范围更大
        int flag = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) ? -1 : 1;
        if (dividend > 0) {
            dividend = -dividend;
        }
        if (divisor > 0) {
            divisor = -divisor;
        }
        return div(dividend, divisor) * flag;

        /**
         * 方法2：借助数组，对时间进行优化
         * 时间复杂度 O(logn) ，空间复杂度 O(logn)
         */
//        // 处理特殊情况
//        if (divisor == 1) {
//            return dividend;
//        } else if (divisor == -1) {
//            if (dividend == std::numeric_limits<int>::min()) {
//                return std::numeric_limits<int>::max();
//            } else {
//                return -dividend;
//            }
//        }
//        // 转为负数，因为负数的范围更大
//        int flag = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) ? -1 : 1;
//        if (dividend > 0) {
//            dividend = -dividend;
//        }
//        if (divisor > 0) {
//            divisor = -divisor;
//        }
//        // 借助数组
//        std::vector<int> dp =  {divisor};
//        while (dp.back() >= dividend - dp.back()) {
//            dp.push_back(dp.back() + dp.back());
//        }
//        int ans = 0;
//        for (int i = dp.size() - 1; i >= 0; --i) {
//            if (dp[i] >= dividend) {
//                ans += (1 << i);
//                dividend -= dp[i];
//            }
//        }
//        return ans * flag;
    }

private:
    // 快速除。用加法实现快速除
    int div(int a, int b) {
        if (a > b) {
            return 0;
        }
        int ans = 1, step = b;
        // 其实是 step + step >= a ，考虑到会溢出，转换为减法运算
        while (step >= a - step) {
            ans += ans;
            step += step;
        }
        return ans + div(a - step, b);
    }
};

int main() {
    std::cout << Solution().divide(7, 3) << std::endl;
    std::cout << Solution().divide(7, -3) << std::endl;
    std::cout << Solution().divide(-7, -3) << std::endl;
    std::cout << Solution().divide(-2147483648, -1) << std::endl;
    std::cout << std::numeric_limits<int>::max() << ", " << std::numeric_limits<int>::min() << std::endl;
    return 0;
}