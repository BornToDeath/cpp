//
// Created by lixiaoqing on 2023/4/16.
//

#include <string>
#include <array>
#include <vector>
#include <iostream>

using std::string;

class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.length(), n = p.length();
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 2; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j >= 2 && p[j - 1] == '*') {
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 2];
                    }
                } else if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    std::cout << Solution().isMatch("aa", "a*") << std::endl;
    return 0;
}