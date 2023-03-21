//
// Created by lixiaoqing on 2023/3/21.
//

#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    int nthUglyNumber(int n) {
        /**
         * 方法1：暴力判断，不AC，时间复杂度超限
         * 时间复杂度 O(NlogN) ，其中 N 为第 n 个丑数所对应的自然数
         * 空间复杂度 O(1)
         */
//        int i = 0;
//        while (n) {
//            ++i;
//            if (isUglyNumber(i)) {
//                --n;
//            }
//        }
//        return i;

        /**
         * 方法2：借助 std::set
         * 时间复杂度 O(nlogn) ，空间复杂度 O(n)
         */
//        std::set<long> s;
//        s.emplace(1);
//        while (n > 1) {
//            auto e = *s.begin();
//            s.insert({e * 2, e * 3, e * 5});
//            s.erase(s.begin());
//            --n;
//        }
//        return static_cast<int>(*s.begin());

        /**
         * 方法3：动态规划，使用三指针。非常巧妙，记住吧！
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        std::vector<int> dp(n);
        dp[0] = 1;
        int p1 = 0, p2 = 0, p3 = 0;
        for (int i = 1; i < n; ++i) {
            auto num = std::min(dp[p1] * 2, std::min(dp[p2] * 3, dp[p3] * 5));
            dp[i] = num;
            if (num == dp[p1] * 2) {
                ++p1;
            }
            if (num == dp[p2] * 3) {
                ++p2;
            }
            if (num == dp[p3] * 5) {
                ++p3;
            }
        }
        return dp.back();
    }

private:
    bool isUglyNumber(int n) {
        while (n % 5 == 0) {
            n /= 5;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }
};

int main() {
    // 1, 2, 3, 4, 5, 6, 8, 9, 10, 12
//    for (int i = 1; i <= 10; ++i) {
//        std::cout << i << ": " << Solution().nthUglyNumber(i) << std::endl;
//    }
    int n = 11;
    std::cout << n << ": " << Solution().nthUglyNumber(n) << std::endl;
    return 0;
}