//
// Created by lixiaoqing on 2022/5/22.
//

#include <vector>
#include <iostream>

using namespace std;

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
        int len = nums.size();
        vector<int> dp(len + 1, 0);
        for (int i = 1; i <= len; ++i) {
            if (i == 1) {
                dp[i] = nums[i - 1];
                continue;
            }
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[len];
    }
};

int main() {
    std::vector<int> nums = {10, 9, 1, 20};//{20, 1, 20, 1, 1, 100};
    std::cout << Solution().rob(nums) << std::endl;
    return 0;
}