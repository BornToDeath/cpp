//
// Created by lixiaoqing on 2023/6/19.
//

#include <string>
#include <list>
#include <iostream>

using std::string;

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        const int n = s.length();
        for (int pos = 0; pos < n; ++pos) {
            // 1. 以当前字符为中心
            for (int i = pos, j = pos; i >= 0 && j <= n && s[i] == s[j]; --i, ++j) {
                ++ans;
            }
            // 2. 以当前字符+下个字符为中心
            if (pos + 1 < n && s[pos] == s[pos + 1]) {
                for (int i = pos, j = pos + 1; i >= 0 && j <= n && s[i] == s[j]; --i, ++j) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main() {
    std::cout << Solution().countSubstrings("abc") << std::endl;
    std::cout << Solution().countSubstrings("aba") << std::endl;
    std::cout << Solution().countSubstrings("abba") << std::endl;
    return 0;
}