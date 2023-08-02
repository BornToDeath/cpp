//
// Created by lixiaoqing on 2023/8/2.
//

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

template<typename T>
void print(const std::vector<std::vector<T>> mat) {
    for (const auto &arr: mat) {
        for (const auto n: arr) {
            std::cout << n << ", ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*
         * 方法: 动态规划, 二维数组
         * 时间复杂度 O(mn), 空间复杂度 O(mn)
         */
        if (text1.empty() || text2.empty()) {
            return 0;
        }
        const int m = text1.length(), n = text2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
//        print(dp);
        return dp.back().back();
    }
};

int main() {
//    auto ans = Solution().longestCommonSubsequence("abcde", "ace");
//    auto ans = Solution().longestCommonSubsequence("bsbininm", "jmjkbkjkv");
//    auto ans = Solution().longestCommonSubsequence("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    auto ans = Solution().longestCommonSubsequence("abc", "def");
    std::cout << ans << std::endl;
    return 0;
}