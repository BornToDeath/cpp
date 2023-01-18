//
// Created by lixiaoqing on 2022/5/9.
//

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     *
     * @param m int整型
     * @param n int整型
     * @return int整型
     */
    int uniquePaths(int m, int n) {
        /**
         * 方法1：动态规划，时间复杂度O(mn), 空间复杂度O(mn)
         * 这个方法可以进行优化，可以使用一维数组，即空间复杂度为 std::min(O(m), O(n))
         */
//        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
//        for (int i = 1; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//        return dp[m - 1][n - 1];

        /**
         * 方法2：递归，时间复杂度O(mn), 空间复杂度O(m+n)
         */
//        if (m == 1 || n == 1) {
//            return 1;
//        }
//        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);

        /**
         * 方法3：组合。时间复杂度O(min(m,n))，空间复杂度O(1)
         */
        // 防止溢出
        long res = 1;
        for (int i = 1; i < n; i++) {
            res = res * (m + i - 1) / i;
        }
        return (int) res;
    }
};

int main() {
    std::cout << Solution().uniquePaths(4, 5) << std::endl;
    return 0;
}