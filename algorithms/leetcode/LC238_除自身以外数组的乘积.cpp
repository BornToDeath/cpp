//
// Created by lixiaoqing on 2022/7/15.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        /**
         * 方法：动态规划，不使用除法运算，时间复杂度 O(n)
         * dp[i] = (A[0] * A[1] * ... * A[i-1]) * (A[i+1] * ... * A[n])
         *       = left[i] * right[i]
         * 其中，left[i] = left[i-1] * A[i-1],
         *      right[i] = right[i+1] * A[i+1]
         */
        if (nums.empty()) {
            return {};
        }
        std::vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = dp[i - 1] * nums[i - 1];
        }
        int mul = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            dp[i] *= mul * nums[i + 1];
            mul *= nums[i + 1];
        }
        return dp;
    }
};

int main() {
//    std::vector<int> nums = {-1, 1, 0, -3, 3};
//    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> nums = {3};
    auto ans = Solution().productExceptSelf(nums);
    for (auto num: ans) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}