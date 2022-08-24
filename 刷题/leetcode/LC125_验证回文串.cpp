//
// Created by lixiaoqing on 2022/8/23.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        /**
         * 方法1：双指针
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        auto isdigit = [](char c) {
//            return c >= '0' && c <= '9';
//        };
//        auto isalphabet = [](char c) {
//            return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
//        };
//        int i = 0, j = s.length() - 1;
//        while (i < j) {
//            while (i < j && !isdigit(s[i]) && !isalphabet(s[i])) {
//                ++i;
//            }
//            while (i < j && !isdigit(s[j]) && !isalphabet(s[j])) {
//                --j;
//            }
//            if (tolower(s[i]) != tolower(s[j])) {
//                return false;
//            }
//            ++i, --j;
//        }
//        return true;

        /**
         * 方法2：基于方法1，使用系统接口 isalnum()
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) {
                ++i;
            }
            while (i < j && !isalnum(s[j])) {
                --j;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            ++i, --j;
        }
        return true;
    }
};

int main() {
    std::cout << Solution().isPalindrome("    n123321    N    ") << std::endl;
    return 0;
}