//
// Created by lixiaoqing on 2022/6/24.
//

#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        /**
         * 方法1：二维数组
         */
//        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (i == 0 || j == 0) {
//                    dp[i][j] = 1;
//                } else {
//                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
//                }
//            }
//        }
//        return dp[m-1][n-1];

        /**
         * 方法2：在方法1的基础上优化为一维数组
         */
//        std::vector<int> dp(n, 1);
//        for (int i = 1; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                dp[j] += dp[j - 1];
//            }
//        }
//        return dp[n - 1];

        /**
         * 方法3：排列组合。总共需要移动 m+n-2 步，其中需要向下移动 m-1 步，
         * 那么有这么多步： —— m-1
         *              |         = (m+n-2)! / (m-1)!(n-1)!
         *              —— m+n-2
         */
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};