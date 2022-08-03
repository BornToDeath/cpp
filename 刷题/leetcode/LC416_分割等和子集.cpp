//
// Created by lixiaoqing on 2022/8/3.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        /**
         * 方法1：递归：转化为 nums 中是否存在一个子集，这个子集的所有元素的和为 sum 的一半。
         * 不AC，时间复杂度超限。
         */
//        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
//        if ((sum & 1) == 1) {
//            return false;
//        }
//        return sumEqualTarget(nums, 0, 0, sum >> 1);

        /**
         * 方法2：01背包问题，动态规划
         * dp[i][j] 表示从数组的 [0, i] 下标范围内是否存在若干个整数的和等于 j ，那么：
         * dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i]]
         * 时间复杂度O(n * target)，空间复杂度O(n * target)，其中 target 是数组元素和的一半
         */
//        if (nums.size() < 2) {
//            return false;
//        }
//        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
//        if ((sum & 1) == 1) {
//            return false;
//        }
//        sum >>= 1;
//        // dp[i][j] 表示从数组的 [0, i] 下标范围内是否存在若干个整数的和等于 j
//        std::vector<std::vector<bool>> dp(nums.size(), std::vector<bool>(sum + 1, false));
//        if (nums[0] <= sum) {
//            dp[0][nums[0]] = true;
//        }
//        for (int i = 1; i < nums.size(); ++i) {
//            for (int j = 1; j < sum + 1; ++j) {
//                if (j == nums[i]) {
//                    dp[i][j] = true;
//                } else if (j > nums[i]) {
//                    // 包含 num[i] 选和不选两种状态
//                    dp[i][j] = dp[i - 1][j - nums[i]] || dp[i - 1][j];
//                } else {
//                    // 此时 num[i] 只有不选状态
//                    dp[i][j] = dp[i - 1][j];
//                }
//            }
//        }
//        return dp[nums.size() - 1][sum];

        /**
         * 方法3：在方法2的基础上，对空间复杂度进行优化
         * 时间复杂度O(n * target)，空间复杂度O(target)，其中 target 是数组元素和的一半
         */
        if (nums.size() < 2) {
            return false;
        }
        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1) {
            return false;
        }
        sum >>= 1;
        std::vector<bool> dp(sum + 1, false);
        if (nums[0] <= sum) {
            dp[nums[0]] = true;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = sum; j >= 0; --j) {
                if (j == nums[i]) {
                    dp[j] = true;
                } else if (j > nums[i]) {
                    // 包含 num[i] 选和不选两种状态
                    dp[j] = dp[j - nums[i]] || dp[j];
                }
            }
        }
        return dp[sum];
    }

private:
    bool sumEqualTarget(vector<int> &nums, int pos, int sum, int target) {
        if (pos >= nums.size()) {
            return false;
        }
        if (sum == target) {
            return true;
        }
        if (sumEqualTarget(nums, pos + 1, sum, target)) {
            return true;
        }
        return sumEqualTarget(nums, pos + 1, sum + nums[pos], target);
    }
};

int main() {
    std::cout << std::boolalpha;
    std::vector<int> nums;
    nums = {1, 5, 11, 5};
    std::cout << Solution().canPartition(nums) << std::endl;
    nums = {2, 2, 3, 5};
    std::cout << Solution().canPartition(nums) << std::endl;
    nums = {3, 3, 3, 4, 5};
    std::cout << Solution().canPartition(nums) << std::endl;
    nums = {14, 9, 8, 4, 3, 2};
    std::cout << Solution().canPartition(nums) << std::endl;
    return 0;
}