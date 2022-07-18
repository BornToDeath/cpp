//
// Created by lixiaoqing on 2022/7/17.
//

#include <iostream>
#include <vector>

void print(std::vector<int> &arr) {
    for (auto num: arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    int numSquares(int n) {
        /**
         * 方法：动态规划。
         * dp[i] 表示组成第 i 个自然数所需要的最少完全平方数的个数，则：dp[i] = std::min(dp[i], dp[i - j^2] + 1)
         */
        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            // 每次将结果更新为最坏结果，比如：i=4，最坏结果4个1，故dp[i]=4
            dp[i] = i;
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }
//        print(dp);
        return dp[n];
    }
};

int main() {
    std::cout << Solution().numSquares(8) << std::endl;
    std::cout << Solution().numSquares(12) << std::endl;
    std::cout << Solution().numSquares(13) << std::endl;
    return 0;
}
