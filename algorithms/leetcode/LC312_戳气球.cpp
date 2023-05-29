//
// Created by lixiaoqing on 2023/5/26.
//

#include <iostream>
#include <vector>
#include <map>

using std::vector;

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        /*
         * 动态规划
         * https://leetcode.cn/problems/burst-balloons/solution/zhe-ge-cai-pu-zi-ji-zai-jia-ye-neng-zuo-guan-jian-/
         * 时间复杂度 O(n^3) , 空间复杂度 O(n^2)
         */
        const int n = nums.size();

        // 辅助数组, 并在首尾各添加 1 , 方便处理边界情况
        std::vector<int> temp(n + 2);
        temp.front() = temp.back() = 1;
        for (int i = 0; i < n; ++i) {
            temp[i + 1] = nums[i];
        }

        // dp[i][j] 表示开区间 (i, j) 内能拿到的最多金币
        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2));

        // len 表示开区间长度
        for (int len = 3; len <= n + 2; ++len) {
            // l 表示开区间左端点, 则 l + len - 1 表示开区间右端点
            for (int l = 0; l <= n + 2 - len; ++l) {
                const int r = l + len - 1;
                // k 为开区间内的索引(代表区间最后一个被戳破的气球)
                for (int k = l + 1; k < r; ++k) {
                    const int left = dp[l][k], right = dp[k][r];
                    const int sum = left + right + temp[l] * temp[k] * temp[r];
                    // 取金币最大值
                    dp[l][r] = std::max(dp[l][r], sum);
                }
            }
        }
        return dp[0][n + 1];
    }
};

int main() {
    std::vector<int> nums = {3, 1, 5, 8};  // 167
    nums = {1, 5};  // 10
    nums = {3, 1, 5};  // 35
    nums = {9, 76, 64, 21};  // 116718
    nums = {9, 76, 64, 21, 97, 60};  // 1086136
    std::cout << Solution().maxCoins(nums) << std::endl;
    return 0;
}