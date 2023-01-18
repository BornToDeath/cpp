//
// Created by lixiaoqing on 2022/6/15.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

void print(std::vector<int> &arr) {
    for (auto num: arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /**
         * 方法1：动态规划
         * dp[i]表示以s[i]结尾的最长无重复字符串的长度，则
         * dp[i]:
         *    = dp[i-1] + 1,                          if s[i] not in map
         *    = std::min(dp[i-1] + 1, i - map[s[i]]), else
         */
//        if (s.empty()) {
//            return 0;
//        }
//        std::vector<int> dp(s.length(), 0);
//        dp[0] = 1;
//        std::unordered_map<char, int> umap;
//        umap[s[0]] = 0;
//        for (int i = 1; i < s.length(); ++i) {
//            if (umap.find(s[i]) == umap.end()) {
//                dp[i] = dp[i - 1] + 1;
//            } else {
//                dp[i] = std::min(dp[i - 1] + 1, i - umap[s[i]]);
//            }
//            umap[s[i]] = i;
//        }
////        print(dp);
//        return *std::max_element(dp.begin(), dp.end());

        /**
         * 方法2：滑动窗口
         *   滑动窗口所包含的元素是不重复的元素，左右窗口的移动规则为：
         *   右窗口：逐个字符移动右窗口直到右窗口到达尾部
         *   左窗口：如果当前这个字符在滑动窗口中出现了，移动左窗口到当前字符之后一个字符的位置
         */
        int max = 0;
        std::unordered_map<char, int> umap;
        for (int i = 0, j = 0; j < s.length(); ++j) {
//            printf("i=%d, j=%d, max=%d\n", i, j, max);
            if (umap.find(s[j]) != umap.end()) {
                i = std::max(umap[s[j]] + 1, i);
            }
            umap[s[j]] = j;
            max = std::max(max, j - i + 1);
        }
        return max;
    }
};

int main() {
    std::string s = "abba";
    std::cout << Solution().lengthOfLongestSubstring(s) << std::endl;
    return 0;
}