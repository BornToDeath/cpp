//
// Created by lixiaoqing on 2022/8/3.
//

#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        /**
         * 方法1：
         */
//        if (x < 0) {
//            return false;
//        }
//        std::string s = std::to_string(x);
//        int i = 0, j = s.length() - 1;
//        while (i < j) {
//            if (s[i] != s[j]) {
//                return false;
//            }
//            ++i;
//            --j;
//        }
//        return true;

        /**
         * 方法2：
         */
        if (x < 0 || x != 0 && x % 10 == 0) {
            return false;
        }
        int y = 0;
        while (x > y) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return x == y || x == y / 10;
    }
};