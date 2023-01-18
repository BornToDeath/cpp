//
// Created by lixiaoqing on 2022/7/8.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        /**
         * 方法1：暴力解法。固定右边界，向左遍历。不AC，时间超限
         */
//        int count = 0;
//        for (int start = 0; start < nums.size(); ++start) {
//            int sum = 0;
//            for (int end = start; end >= 0; --end) {
//                sum += nums[end];
//                if (sum == k) {
//                    count++;
//                }
//            }
//        }
//        return count;

        /**
         * 方法2：构建前缀和数组。不AC，时间超限
         */
//        int size = nums.size();
//        std::vector<int> dp(size + 1);
//        for (int i = 0; i < size; ++i) {
//            dp[i + 1] = dp[i] + nums[i];
//        }
//        int count = 0;
//        for (int i = 0; i < size; ++i) {
//            for (int j = i; j < size; ++j) {
//                if (dp[j + 1] - dp[i] == k) {
//                    ++count;
//                }
//            }
//        }
//        return count;

        /**
         * 方法2：前缀和 + std::unordered_map
         * dp[sum] = count 表示前缀和为 sum 的数组个数有 count 个
         */
        std::unordered_map<int, int> dp;
        dp[0] = 1;
        int count = 0, sum = 0;
        for (auto num: nums) {
            sum += num;
            if (dp.count(sum - k)) {
                count += dp[sum - k];
            }
            ++dp[sum];
        }
        return count;
    }
};

int main() {
    std::vector<int> nums = {1, 1, 1, 4, 1};
    int k = 2;
    std::cout << Solution().subarraySum(nums, k) << std::endl;
    return 0;
}