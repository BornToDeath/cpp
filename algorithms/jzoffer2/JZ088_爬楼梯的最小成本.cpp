//
// Created by boss on 2023/5/11.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        /*
         * 方法1: 动态规划: n个阶梯对应的下标为0~n-1,楼层顶部对应的下标为n,问题转化为计算到达下标n的最小花费
         * 时间复杂度 O(n), 空间复杂度 O(n)
         */
        // dp[i] 为到达下标 i 的最小花费
//        std::vector<int> dp(cost.size() + 1);
//        for (int i = 2; i < dp.size(); ++i) {
//            dp[i] = std::min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
//        }
//        return dp.back();

        /*
         * 方法2: 方法1的优化
         * 时间复杂度 O(n), 空间复杂度 O(1)
         */
        int pre = 0, cur = 0;
        for (int i = 1; i < cost.size(); ++i) {
            auto next = std::min(pre + cost[i - 1], cur + cost[i]);
            pre = cur;
            cur = next;
        }
        return cur;
    }
};

int main() {
    std::vector<int> nums = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
//    nums = {10, 15, 20};
    std::cout << Solution().minCostClimbingStairs(nums) << std::endl;
    return 0;
}