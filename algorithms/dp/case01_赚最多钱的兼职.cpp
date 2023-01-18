//
// Created by lixiaoqing on 2023/1/4.
//

/**
 * 详情见：https://mp.weixin.qq.com/s/hzMsN8qvL5FjfSA_IaeDbw
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int> &startTime, std::vector<int> &endTime, std::vector<int> &profit) {
        /**
         * 方法1：递归
         */
//        return maxProfit(startTime, endTime, profit, 0);

        /**
         * 方法2：迭代（推荐）
         */
        const int n = profit.size();
        std::vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            int res1 = profit[i];
            for (int j = i + 1; j <= n; ++j) {
                if (startTime[j] >= endTime[i]) {
                    res1 += dp[j];
                    break;
                }
            }
            dp[i] = std::max(res1, dp[i + 1]);
        }
        return dp[0];
    }

private:
    // 第 pos 个工作到最后一个工作中进行选择所能获取的最多报酬
    int maxProfit(const std::vector<int> &startTime, const std::vector<int> &endTime,
                  const std::vector<int> &profit, int pos) {
        if (pos >= profit.size()) {
            return 0;
        }

        // 1. 接收当前的工作
        int res1 = profit[pos];
        // 找到下一个与当前工作时间不冲突的工作
        for (int i = pos + 1; i < profit.size(); ++i) {
            if (startTime[i] >= endTime[pos]) {
                res1 += maxProfit(startTime, endTime, profit, i);
                break;
            }
        }

        // 2. 不接收当前的工作
        int res2 = maxProfit(startTime, endTime, profit, pos + 1);

        // 1、2 取最大的即为最多报酬
        return std::max(res1, res2);
    }
};


int main() {
    std::vector<int> beginTime = {1, 2, 3, 4, 6};
    std::vector<int> endTime = {3, 5, 10, 6, 9};
    std::vector<int> profit = {20, 20, 100, 70, 60};
    std::cout << Solution().maxProfit(beginTime, endTime, profit) << std::endl;
    return 0;
}