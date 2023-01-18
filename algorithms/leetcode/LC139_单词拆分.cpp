//
// Created by lixiaoqing on 2022/7/1.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        /**
         * 方法1：递归
         */
//        std::vector<int> dp(s.length(), 0);
//        return dfs(s, 0, wordDict, dp);

        /**
         * 方法2：动态规划
         * dp[i] 表示 s 前 i 个字符所组成的字符串是否可以由 wordDict 中的若干字符串组成
         */
        std::unordered_set<std::string> set(wordDict.begin(), wordDict.end());
        std::vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && set.find(s.substr(j, i - j)) != set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[dp.size() - 1];
    }

private:
    bool dfs(std::string s, int pos, std::vector<std::string> &words, std::vector<int> &dp) {
//        printf("pos=%d\n", pos);
        if (pos > s.length()) {
            return false;
        } else if (pos == s.length() || dp[pos] == 1) {
            return true;
        } else if (dp[pos] == -1) {
            return false;
        }
        for (auto &str: words) {
            if (pos + str.length() <= s.length() && str == s.substr(pos, str.length())) {
                if (dfs(s, pos + str.length(), words, dp)) {
                    dp[pos] = 1;
                    return true;
                }
            }
        }
        dp[pos] = -1;
        return false;
    }
};

int main() {
    std::string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    std::vector<std::string> words = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
//    std::string str = "leetcode";
//    std::vector<std::string> words = {"leet", "code"};
    std::cout << Solution().wordBreak(str, words) << std::endl;
    return 0;
}