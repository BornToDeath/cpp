//
// Created by lixiaoqing on 2022/7/6.
//

#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /**
         * 方法1：动态规划
         */
//        if (nums.empty()) {
//            return 0;
//        }
//        std::vector<int> dp(nums);
//        for (int i = 1; i < dp.size(); ++i) {
//            if (i == 1) {
//                dp[i] = std::max(dp[0], dp[1]);
//            } else {
//                dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
//            }
//        }
//        return dp[dp.size() - 1];

        /**
         * 方法2：在方法1的基础上进行优化
         */
        if (nums.empty()) {
            return 0;
        }
        int x = 0, y = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int temp = std::max(y, x + nums[i]);
            x = y;
            y = temp;
        }
        return y;
    }
};