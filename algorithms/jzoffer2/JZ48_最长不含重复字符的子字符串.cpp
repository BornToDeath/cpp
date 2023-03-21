//
// Created by lixiaoqing on 2023/3/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /**
         * 方法1：动态规划
         *   dp[i] = std::min(dp[i-1] + 1, i - index[c])
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        const int len = s.length();
//        std::vector<int> dp(len + 1);
//        std::unordered_map<char, int> index;
//        for (int i = 0; i < len; ++i) {
//            if (index.count(s[i]) == 0) {
//                dp[i + 1] = dp[i] + 1;
//            } else {
//                dp[i + 1] = std::min(dp[i] + 1, i - index[s[i]]);
//            }
//            index[s[i]] = i;
//        }
//        return *std::max_element(dp.begin(), dp.end());

        /**
         * 方法2：滑动窗口
         *   滑动窗口所包含的元素是不重复的元素，左右窗口的移动规则为：
         *   右窗口：逐个字符移动右窗口直到右窗口到达尾部
         *   左窗口：如果当前这个字符在滑动窗口中出现了，移动左窗口至最无重复子串的最左边位置
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        int max = 0;
        std::unordered_map<char, int> index;
        for (int l = -1, r = 0; r < s.length(); ++r) {
            if (index.count(s[r])) {
                l = std::max(l, index[s[r]]);
            }
            index[s[r]] = r;
            max = std::max(max, r - l);
        }
        return max;
    }
};

int main() {
    std::cout << Solution().lengthOfLongestSubstring(" ") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("tmmzuxt") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("abcad") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("pwwkew") << std::endl;
    return 0;
}