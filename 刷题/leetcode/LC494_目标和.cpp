//
// Created by lixiaoqing on 2022/8/8.
//

#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        /**
         * 方法1：递归
         * 时间复杂度 O(2^n) ，空间复杂度 O(n)
         */
//        findTarget(nums, 0, 0, target);
//        return count;

        /**
         * 方法2：动态规划，01背包问题
         * 参考：https://leetcode.cn/problems/target-sum/solution/mu-biao-he-by-leetcode-solution-o0cp/
         * dp[i][j] 表示在数组中前 i 个元素中选取若干元素，使得这些元素之和等于 j 的方案数
         * 时间复杂度 O(n * (sum - target)) ，空间复杂度 O(n * (sum - target))
         */
//        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
//        int diff = sum - target;
//        if (diff < 0 || diff % 2 != 0) {
//            return 0;
//        }
//        int neg = diff >> 1, size = nums.size();
//        std::vector<std::vector<int>> dp(size + 1, std::vector<int>(neg + 1, 0));
//        dp[0][0] = 1;
//        for (int i = 1; i <= size; ++i) {
//            for (int j = 0; j <= neg; ++j) {
//                if (j < nums[i - 1]) {
//                    dp[i][j] = dp[i - 1][j];
//                } else {
//                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
//                }
//            }
//        }
//        return dp[size][neg];

        /**
         * 方法3：在方法2的基础上进行优化
         * 时间复杂度 O(n * (sum - target)) ，空间复杂度 O(sum - target)
         */
        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int neg = diff >> 1;
        std::vector<int> dp(neg + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = neg; j >= 0; --j) {
                if (j >= nums[i - 1]) {
                    dp[j] += dp[j - nums[i - 1]];
                }
            }
        }
        return dp[neg];
    }

private:
    void findTarget(std::vector<int> &nums, int pos, int sum, int target) {
        if (pos == nums.size()) {
            if (sum == target) {
                ++count;
            }
            return;
        }
        findTarget(nums, pos + 1, sum + nums[pos], target);
        findTarget(nums, pos + 1, sum - nums[pos], target);
    }

private:
    int count{0};
};


int main() {
    std::vector<int> nums = {1, 1, 1, 1, 1};
    std::cout << Solution().findTargetSumWays(nums, 3) << std::endl;
    return 0;
}
