//
// Created by lixiaoqing on 2023/2/13.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        /**
         * 方法1：时间复杂度 O(n^2) ，空间复杂度 O(n)
         */
//        int len = s.length();
//        for (int i = 2; i <= len; ++i) {
//            if (len % i != 0) {
//                continue;
//            }
//            int l = len / i;
//            auto sub_str = s.substr(0, l);
//            for (int j = 1; j < i; ++j) {
//                if (s.substr(j * l, l) != sub_str) {
//                    break;
//                }
//                if (j == i - 1) {
//                    return true;
//                }
//            }
//        }
//        return false;

        /**
         * 方法2：时间复杂度 O(n^2) ，空间复杂度 O(1)
         */
//        int len = s.length();
//        for (int i = 1; i * 2 <= len; ++i) {
//            if (len % i != 0) {
//                continue;
//            }
//            for (int j = i; j < len; ++j) {
//                if (s[j] != s[j - i]) {
//                    break;
//                }
//                if (j == len - 1) {
//                    return true;
//                }
//            }
//        }
//        return false;

        /**
         * 方法3：时间复杂度 O(n) ，空间复杂度 O(1)
         * 参考：https://leetcode.cn/problems/repeated-substring-pattern/solution/by-carlsun-2-g3iz/
         */
        return (s + s).substr(1, s.length() * 2 - 2).find(s) != std::string::npos;
    }
};

int main() {
    std::cout << Solution().repeatedSubstringPattern("aba") << std::endl;
    std::cout << Solution().repeatedSubstringPattern("abab") << std::endl;
    std::cout << Solution().repeatedSubstringPattern("aaaaaaaaa") << std::endl;
    std::cout << Solution().repeatedSubstringPattern("abcabcabcabc") << std::endl;
    return 0;
}