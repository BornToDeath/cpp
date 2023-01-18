//
// Created by lixiaoqing on 2022/5/18.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(std::vector<std::vector<int>> &matrix) {
    for (const auto &arr: matrix) {
        for (auto num: arr) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    /**
     * longest common subsequence
     * 注意：题目要求的返回的是最长子序列而不是子串，子序列可以不连续，但是子串需要连续！
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        if (s1.empty() || s2.empty()) {
            return "-1";
        }
        // 创建一个 +1 大小的二维数组在操作时会简化逻辑
        int rows = s1.length() + 1;
        int cols = s2.length() + 1;
        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        std::string str;
        int i = rows - 1;
        int j = cols - 1;
        while (i > 0 && j > 0 && dp[i][j] != 0) {
            if (dp[i][j] == dp[i][j - 1]) {
                // 来自于左方向
                j--;
            } else if (dp[i][j] == dp[i - 1][j]) {
                // 来自于上方向
                i--;
            } else {
                // 来自于左上方向
                str += s1[i - 1];
                --i;
                --j;
            }
        }
        std::reverse(str.begin(), str.end());
        return (str.empty()) ? "-1" : str;
    }
};

int main() {
    std::string str1 = "1A2C3D4B56";
    std::string str2 = "B1D23A456A";
    std::cout << Solution().LCS(str1, str2) << std::endl;
    return 0;
}