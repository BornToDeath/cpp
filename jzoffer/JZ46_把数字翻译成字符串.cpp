//
// Created by lixiaoqing on 2022/3/31.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printArray(const std::vector<int> &nums) {
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
}

class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        /**
         * 方法：动态规划
         * 注意："03"这种类型的字符串是无法转换的！
         */
        if (nums.empty() || nums[0] == '0') {
            return 0;
        }
        std::vector<int> dp(nums.length() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.length(); ++i) {
            dp[i + 1] = (nums[i] == '0') ? 0 : dp[i];
            if (i == 0) {
                continue;
            }
            if (nums[i - 1] == '1' || (nums[i - 1] == '2' && nums[i] <= '6')) {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp.back();
    }
};

int main() {
//    std::string str = "12021";
    std::string str = "31717126241541717";
    std::cout << str << std::endl;
    std::cout << Solution().solve(str) << std::endl;
}