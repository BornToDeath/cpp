//
// Created by lixiaoqing on 2023/5/18.
//

#include <vector>
#include <bitset>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<int> countBits(int n) {
        /*
         * 方法1: 利用 std::bitset
         * 时间复杂度 O(n * sizeof(int)), 空间复杂度 O(1)
         */
//        std::vector<int> ans(n + 1);
//        for (int i = 1; i <= n; ++i) {
//            ans[i] = std::bitset<32>(i).count();
//        }
//        return ans;

        /*
         * 方法2: 动态规划, dp[i] 表示整数 i 的二进制中 1 的个数, 那么:
         *   1. 如果 i 是 2 的幂, dp[i] = 1;
         *   2. 否则, dp[i] = dp[上一个2的幂的整数j] + dp[i - j], 其中 dp[j] = 1
         * 那么如何判断一个整数是否是 2 的幂呢? 利用 n&(n-1) 是否等于 0 来判断
         * 时间复杂度 O(n), 空间复杂度 O(1)
         */
//        std::vector<int> ans(n + 1);
//        for (int i = 1, j = 0; i <= n; ++i) {
//            if ((i & (i - 1)) == 0) {
//                j = i;
//            }
//            ans[i] = ans[i - j] + 1;
//        }
//        return ans;

        /*
         * 方法3: 动态规划, 如何计算一个整数二进制中1的个数呢, 利用 n&(n-1) 的方法, 此处也可利用此方法,
         * n&(n-1) 每次都会去掉一个1, 那么 dp[i] = dp[i & (i - 1)] + 1
         * 时间复杂度 O(n), 空间复杂度 O(1)
         */
        std::vector<int> ans(n + 1);
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().countBits(20);
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << i << " : " << ans[i] << std::endl;
    }
    return 0;
}