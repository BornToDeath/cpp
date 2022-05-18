//
// Created by lixiaoqing on 2022/5/18.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(std::vector<std::vector<int>> &matrix) {
    for (const auto &arr: matrix) {
        for (auto num: arr) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
}

void print(std::vector<int> &arr) {
    for (auto num: arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        /**
         * 方法1：动态规划
         */
//        if (str1.empty() || str2.empty()) {
//            return "";
//        }
//        int maxLen = 0;
//        int pos = -1;
//        int rows = str1.length() + 1;
//        int cols = str2.length() + 1;
//        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
//        for (int i = 1; i < rows; ++i) {
//            for (int j = 1; j < cols; ++j) {
//                if (str1[i - 1] == str2[j - 1]) {
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                    if (dp[i][j] > maxLen) {
//                        maxLen = dp[i][j];
//                        pos = i - 1;
//                    }
//                }
//            }
//        }
//        std::string str;
//        if (maxLen > 0) {
//            str = str1.substr(pos - maxLen + 1, maxLen);
//        }
//        return str;

        /**
         * 方法2：在方法1的基础上进行优化，由于二维数组在计算每个元素的值时只依赖其左上角的元素，
         * 所以可以将二维数组优化为一维数组
         */
        if (str1.empty() || str2.empty()) {
            return "";
        }
        int maxLen = 0;
        int pos = -1;
        std::vector<int> dp(str2.length(), 0);
        for (int i = 0; i < str1.length(); ++i) {
            // str2需要倒序计算，否则数组的值会被覆盖
            for (int j = str2.length() - 1; j >= 0; --j) {
                dp[j + 1] = (str1[i] == str2[j]) ? (dp[j] + 1) : 0;
                if (dp[j + 1] > maxLen) {
                    maxLen = dp[j + 1];
                    pos = j;
                }
            }
        }
        std::string str;
        if (maxLen > 0) {
            str = str2.substr(pos - maxLen + 1, maxLen);
        }
        return str;
    }
};

int main() {
    std::string str1 = "1AB2345CD";
    std::string str2 = "12345EF";
    std::cout << Solution().LCS(str1, str2) << std::endl;
    return 0;
}