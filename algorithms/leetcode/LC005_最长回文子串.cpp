//
// Created by lixiaoqing on 2022/6/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(std::vector<std::vector<int>> &mat) {
    for (auto &arr : mat) {
        for (auto num :arr) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    string longestPalindrome(string s) {
        /**
         * 方法1：插入 '#' ，时间复杂度O(n), 空间复杂度O(n)
         */
        std::string str("#");
        for (auto ch: s) {
            str.push_back(ch);
            str.push_back('#');
        }
        // 记录最长回文子串的首尾下标
        int left = 0, right = 0;
        for (int i = 0; i < str.length(); ++i) {
            int l = i, r = i;
            while (l - 1 >= 0 && r + 1 < str.length() && str[l - 1] == str[r + 1]) {
                --l;
                ++r;
            }
            if (r - l + 1 > right - left + 1) {
                left = l;
                right = r;
            }
        }
        std::string res;
        for (int i = left; i <= right; ++i) {
            if (str[i] != '#') {
                res.push_back(str[i]);
            }
        }
        return res;

        /**
         * 方法2：动态规划
         *   dp[i][j] = dp[i+1][j-1] + 2
         *   dp[i][j]表示第i个字符到第j个字符所表示的回文串的长度，只用矩阵的右上部分
         *   时间复杂度O(n^2)，空间复杂度O(n^2)
         */
//        int len = s.length();
//        std::vector<std::vector<int>> dp(len, std::vector<int>(len, 0));
//        int left = 0, right = 0;
//        for (int i = len - 1; i >= 0; --i) {
//            for (int j = i; j < len; ++j) {
//                if (i == j) {
//                    // 对角线
//                    dp[i][j] = 1;
//                } else if (s[i] == s[j]) {
//                    if (i + 1 == j) {
//                        // 次对角线
//                        dp[i][j] = 2;
//                    } else if (dp[i + 1][j - 1] != 0) {
//                        dp[i][j] = dp[i + 1][j - 1] + 2;
//                    }
//                }
//                if (dp[i][j] > right - left + 1) {
//                    left = i;
//                    right = j;
//                }
//            }
//        }
//        return s.substr(left, right - left + 1);
    }
};

int main() {
    std::string str = "a";
    std::cout << Solution().longestPalindrome(str) << std::endl;
    return 0;
}