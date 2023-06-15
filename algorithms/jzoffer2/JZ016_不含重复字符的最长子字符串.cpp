//
// Created by lixiaoqing on 2023/6/15.
//

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        std::unordered_map<char, int> map;
        for (int i = -1, j = 0; j < s.length(); ++j) {
            if (map.count(s[j])) {
                i = std::max(i, map[s[j]]);
            }
            ans = std::max(ans, j - i);
            map[s[j]] = j;
        }
        return ans;
    }
};

int main() {
    std::cout << Solution().lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("pwwkew") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("aab") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("abcdefg") << std::endl;
    std::cout << Solution().lengthOfLongestSubstring("abba") << std::endl;
    return 0;
}