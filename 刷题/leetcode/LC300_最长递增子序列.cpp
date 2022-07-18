//
// Created by lixiaoqing on 2022/7/18.
//

#include <vector>
#include <iostream>

using namespace std;

void print(std::vector<int> &nums) {
    for (auto num: nums) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;;
}

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        /**
         * 方法：动态规划。dp[i] 表示第 i 个元素结尾的最长递增子序列的长度
         */
        if (nums.empty()) {
            return 0;
        }
        std::vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
//        print(dp);
        return *std::max_element(dp.begin(), dp.end());
    }
};

int main() {
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << Solution().lengthOfLIS(nums) << std::endl;
    return 0;
}