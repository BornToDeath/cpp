//
// Created by lixiaoqing on 2022/5/9.
//

#include <iostream>
#include <vector>

using namespace std;

void printArray(const std::vector<int> &nums) {
    std::for_each(nums.begin(), nums.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param cost int整型vector
     * @return int整型
     */
    int minCostClimbingStairs(vector<int> &cost) {
        /**
         * 方法1：
         */
//        // 上 i 级台阶所花费的最小费用 dp[i]
//        std::vector<int> dp(cost.size() + 3, 0);
//        for (int i = 0; i < cost.size(); ++i) {
//            if (i == 0) {
//                dp[i + 2] = dp[i + 1] = cost[0];
//            } else if (i == 1) {
//                dp[i + 1] = std::min(cost[0], cost[1]);
//                dp[i + 2] = cost[1];
//            } else {
//                dp[i + 1] = std::min(dp[i + 1], dp[i] + cost[i]);
//                dp[i + 2] = dp[i] + cost[i];
//            }
//        }
//        return dp[dp.size() - 3];

        /**
         * 方法2：
         */
        // dp[i] 表示爬到第 i 阶楼梯需要的最小花费
        std::vector<int> dp(cost.size() + 1, 0);
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[dp.size() - 1];
    }
};

int main() {
    std::vector<int> res = {1, 100, 1, 1, 1, 90, 1, 1, 80, 1};
    printArray(res);
    std::cout << Solution().minCostClimbingStairs(res) << std::endl;
    return 0;
}