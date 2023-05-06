//
// Created by lixiaoqing on 2023/5/6.
//

#include <iostream>
#include <vector>
#include <string>

using std::string;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.size(), n = word2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main() {

    return 0;
}