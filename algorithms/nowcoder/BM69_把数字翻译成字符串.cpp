//
// Created by lixiaoqing on 2022/10/11.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        /**
         * 方法1：递归
         */
//        if (nums.empty()) {
//            return 1;
//        }
//        if (nums[0] == '0') {
//            return 0;
//        }
//        auto count = solve(nums.substr(1));
//        if (nums.length() > 1 && nums.substr(0, 2) <= "26") {
//            count += solve(nums.substr(2));
//        }
//        return count;

        /**
         * 方法2：动态规划
         * dp[i + 1] = dp[i] + dp[i - 1]
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        if (nums.empty() || nums[0] == '0') {
            return 0;
        }
        std::vector<int> dp(nums.length() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.length(); ++i) {
            if (nums[i] != '0') {
                dp[i + 1] = dp[i];
            }
            if (i == 0) {
                continue;
            }
            if (nums[i - 1] == '1' || nums[i - 1] == '2' && nums[i] <= '6') {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp.back();
    }
};

int main() {
    std::string str = "10";
    std::cout << Solution().solve(str) << std::endl;
    return 0;
}