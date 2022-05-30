//
// Created by lixiaoqing on 2022/5/22.
//

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> &nums) {
    for (auto num: nums) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int rob(vector<int> &nums) {
        /**
         * 两种情况：
         * 1. 如果第一家一定会被偷，dp[1] = nums[0], dp[2] = dp[1] 。
         * 2. 如果第一家不会被偷，dp[1] = 0, dp[2] = nums[1] 。
         */
        // 如果第一家一定会被偷
        int len = nums.size();
        std::vector<int> dp1(len + 1);
        for (int i = 1; i <= len; ++i) {
            if (i == 1) {
                dp1[i] = nums[0];
            } else if (i == 2 || i == len) {
                dp1[i] = dp1[i - 1];
            } else {
                dp1[i] = std::max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
            }
        }
//        print(dp1);
        // 如果第一家不会被偷
        std::vector<int> dp2(len + 1);
        for (int i = 1; i <= len; ++i) {
            if (i == 1) {
                dp2[i] = 0;
            } else {
                dp2[i] = std::max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
            }
        }
//        print(dp2);
        return std::max(dp1[len], dp2[len]);
    }
};

int main() {
    std::vector<int> nums = {1, 3, 6};
    std::cout << Solution().rob(nums) << std::endl;
    return 0;
}