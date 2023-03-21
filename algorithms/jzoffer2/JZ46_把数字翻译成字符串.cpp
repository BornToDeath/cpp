//
// Created by lixiaoqing on 2023/3/21.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int translateNum(int num) {
        /**
         * 方法1：递归
         * 时间复杂度 O(n ^ 2) ，空间复杂度 O(n)
         */
//        return dfs(std::move(std::to_string(num)), 0);

        /**
         * 方法2：动态规划: dp[i + 1] = dp[i] + dp[i - 1]
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        std::string s = std::to_string(num);
        const int len = s.length();
        std::vector<int> dp(len + 1);
        dp[0] = dp[1] = 1;
        for (int i = 1; i < len; ++i) {
            dp[i + 1] = dp[i];
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '5')) {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[len];
    }

private:
    int dfs(std::string &&s, int pos) {
        if (pos >= s.length() - 1) {
            return 1;
        }
        int count = dfs(std::forward<std::string &&>(s), pos + 1);
        if (s[pos] == '1' || (pos + 1 < s.length() && s[pos] == '2' && s[pos + 1] <= '5')) {
            count += dfs(std::forward<std::string &&>(s), pos + 2);
        }
        return count;
    }
};

int main() {
    std::cout << Solution().translateNum(12258) << std::endl;
    return 0;
}