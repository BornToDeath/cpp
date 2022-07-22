//
// Created by lixiaoqing on 2022/7/21.
//

#include <vector>
#include <iostream>
#include <limits>
#include <bitset>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        /**
         * 方法：动态规划。时间复杂度 O(n) ，空间复杂度 O(n)
         * 每天只处于两种状态：持有或不持有股票，而对于不持有，又可分为冷汗期和非冷冻期，故状态转移方程定义如下：
         * dp[i] 表示第 i 天结束之后的状态：
         * 【状态1】dp[i][0]: 第 i 天结束之后，持有股票时的累计最大收益（持有）
         * 【状态2】dp[i][1]: 第 i 天结束之后，不持有股票并且处于冷冻期的累计最大收益（卖出）
         * 【状态3】dp[i][2]: 第 i 天结束之后，不持有股票并且不处于冷冻期的累计最大收益（冷冻或不买）
         */
        if (prices.empty()) {
            return 0;
        }
        const int size = prices.size();
        std::vector<std::vector<int>> dp(size, std::vector<int>(3, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i < size; ++i) {
            // 持有：今天持有的话，前一天要么也是「持有」，要么是「冷冻或不买」状态
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            // 卖出：今天卖出的话，前一天必须是「持有」
            dp[i][1] = dp[i - 1][0] + prices[i];
            // 冷冻或不买：前一天必须是「卖出」或「不买」的状态
            dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]);
        }
        return std::max(dp[size - 1][1], dp[size - 1][2]);

        /**
         * 方法2：在方法1的基础上进行优化。时间复杂度 O(n) ，空间复杂度 O(1)
         * 由于 dp[i] 的值只依赖于 dp[i-1] 的值，故可对空间进行优化
         */
//        if (prices.empty()) {
//            return 0;
//        }
//        const int size = prices.size();
//        int dp1 = -prices[0], dp2 = 0, dp3 = 0;
//        for (int i = 1; i < size; ++i) {
//            // 持有：今天持有的话，前一天要么也是「持有」，要么是「冷冻或不买」状态
//            int dp11 = std::max(dp1, dp3 - prices[i]);
//            // 卖出：今天卖出的话，前一天必须是「持有」
//            int dp22 = dp1 + prices[i];
//            // 冷冻或不买：前一天必须是「卖出」或「不买」的状态
//            int dp33 = std::max(dp2, dp3);
//            dp1 = dp11;
//            dp2 = dp22;
//            dp3 = dp33;
//        }
//        return std::max(dp2, dp3);

        /**
         * 方法3：在方法2的基础上，在代码写法上进行优化
         */
//        if (prices.empty()) {
//            return 0;
//        }
//        const int size = prices.size();
//        int dp1 = -prices[0], dp2 = 0, dp3 = 0;
//        for (int i = 1; i < size; ++i) {
//            std::tie(dp1, dp2, dp3) = std::make_tuple(std::max(dp1, dp3 - prices[i]), dp1 + prices[i], std::max(dp2, dp3));
//        }
//        return std::max(dp2, dp3);
    }
};

int main() {
//    std::vector<int> prices = {1, 6, 7, 2, 10};
    std::vector<int> prices = {1, 2, 10, 0, 3};
    std::cout << Solution().maxProfit(prices) << std::endl;
    return 0;
}