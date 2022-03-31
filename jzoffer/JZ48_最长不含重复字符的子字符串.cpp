//
// Created by lixiaoqing on 2022/3/30.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        /**
         * 方法1：动态规划
         *   dp[i]表示i处字符结尾的最大长度，则：
         *   dp[i]:
         *     = dp[i-1] + 1,                     if s[i] not in map
         *     = min(dp[i-1] + 1, i - map[s[i]]), or
         */
//        std::vector<int> dp(s.length() + 1, 0);
//        std::unordered_map<char, int> umap;
//        int maxLength = 0;
//        for (int i = 0; i < s.length(); ++i) {
//            auto it = umap.find(s[i]);
//            if (it == umap.end()) {
//                dp[i + 1] = dp[i] + 1;
//            } else {
//                dp[i + 1] = std::min(dp[i] + 1, i - it->second);
//            }
//            umap[s[i]] = i;
//            maxLength = std::max(maxLength, dp[i + 1]);
//        }
//        return maxLength;

        /**
         * 方法2：滑动窗口
         *   滑动窗口所包含的元素是不重复的元素，左右窗口的移动规则为：
         *   右窗口：逐个字符移动右窗口直到右窗口到达尾部
         *   左窗口：如果当前这个字符在滑动窗口中出现了，移动左窗口到当前字符的位置
         */
        std::unordered_map<char, int> umap;
        int maxLength = 0;
        for (int left = -1, right = 0; right < s.length(); ++right) {
            if (umap.find(s[right]) != umap.end()) {
                left = std::max(left, umap[s[right]]);
            }
            umap[s[right]] = right;
            maxLength = std::max(maxLength, right - left);
        }
        return maxLength;
    }
};

int main() {
    std::string s = " ";
    std::cout << Solution().lengthOfLongestSubstring(s) << std::endl;
    return 0;
}