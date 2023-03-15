//
// Created by lixiaoqing on 2023/3/15.
//

#include <string>
#include <vector>
#include <iostream>

using std::string;

class Solution {
public:
    bool isNumber(string s) {
        /**
         * 方法1：暴力判断
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int pos = 0;
        while (pos < s.length() && s.at(pos) == ' ') {
            ++pos;
        }
        if (pos < s.length() && (s[pos] == '+' || s[pos] == '-')) {
            ++pos;
        }
        bool hasInteger = false;
        while (pos < s.length() && s[pos] >= '0' && s[pos] <= '9') {
            hasInteger = true;
            ++pos;
        }
        bool hasDecimal = false;
        if (pos < s.length() && s[pos] == '.') {
            ++pos;
            bool hasNum = false;
            while (pos < s.length() && s[pos] >= '0' && s[pos] <= '9') {
                hasNum = true;
                ++pos;
            }
            if (!hasInteger && !hasNum) {
                return false;
            }
            hasDecimal = true;
        }
        if (!hasInteger && !hasDecimal) {
            return false;
        }
        if (pos < s.length() && (s[pos] == 'e' || s[pos] == 'E')) {
            ++pos;
            if (pos < s.length() && (s[pos] == '+' || s[pos] == '-')) {
                ++pos;
            }
            bool hasNum = false;
            while (pos < s.length() && s[pos] >= '0' && s[pos] <= '9') {
                hasNum = true;
                ++pos;
            }
            if (!hasNum) {
                return false;
            }
        }
        while (pos < s.length() && s[pos] == ' ') {
            ++pos;
        }
        return pos >= s.length();

        /**
         * 方法2：有限状态自动机
         * 参考：https://leetcode.cn/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/solution/biao-shi-shu-zhi-de-zi-fu-chuan-by-leetcode-soluti/
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
    }
};

int main() {
//    std::string s = "-1E-16";
//    std::cout << Solution().isNumber(s) << std::endl;
    std::vector<std::string> sss = {"+100", "5e2", "-123", "3.1416", "-1E-16", "0123",
                                    "12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"};
    for (auto &s: sss) {
        std::cout << Solution().isNumber(s) << std::endl;
    }
    return 0;
}