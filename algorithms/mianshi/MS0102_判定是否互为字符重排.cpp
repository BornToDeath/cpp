//
// Created by lixiaoqing on 2023/5/30.
//

#include <iostream>
#include <array>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        /*
         * 方法: 哈希表
         * 时间复杂度 O(m + n) , 空间复杂度 O(S) , 其中 S 为字符集的大小 128
         */
        if (s1.length() != s2.length()) {
            return false;
        }
        std::unordered_map<char, int> dp;
        for (auto c: s1) {
            ++dp[c];
        }
        for (auto c: s2) {
            --dp[c];
            if (dp[c] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution().CheckPermutation("abc", "bca") << std::endl;
    std::cout << Solution().CheckPermutation("abca", "bca") << std::endl;
    return 0;
}