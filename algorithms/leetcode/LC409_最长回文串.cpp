//
// Created by lixiaoqing on 2023/2/3.
//

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_map<char, int> m;
        for (auto c: s) {
            ++m[c];
        }
        int len = 0;
        for (auto &it: m) {
            len += it.second / 2 * 2;  // 左右放置字符的个数
            if (len % 2 == 0 && it.second % 2 == 1) {  // 中心放置一个字符
                ++len;
            }
        }
        return len;
    }
};

int main() {
    std::cout << Solution().longestPalindrome("a") << std::endl;
    std::cout << Solution().longestPalindrome("bb") << std::endl;
    std::cout << Solution().longestPalindrome("abccccdd") << std::endl;
    std::cout << Solution().longestPalindrome("aaaaacc") << std::endl;
    return 0;
}