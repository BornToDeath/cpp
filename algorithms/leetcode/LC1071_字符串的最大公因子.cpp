//
// Created by lixiaoqing on 2023/6/28.
//

#include <string>
#include <iostream>
#include <numeric>

using std::string;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        /*
         * 方法1: 枚举
         */
//        const int len1 = str1.length(), len2 = str2.length();
//        if (len1 < len2) {
//            return gcdOfStrings(str2, str1);
//        }
//        for (int i = 1; i <= len2; ++i) {
//            if (len2 % i != 0) {
//                continue;
//            }
//            auto str = str2.substr(0, len2 / i);
//            if (!check(str2, str)) {
//                continue;
//            }
//            if (check(str1, str)) {
//                return str;
//            }
//        }
//        return "";

        /*
         * 方法2: 数学, 什么叫优雅
         */
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        return str1.substr(0, gcd(str1.length(), str2.length()));
    }

private:
    static bool check(const std::string_view str1, const std::string_view str2) {
        for (int i = 0; i < str1.length(); i += str2.length()) {
            if (str1.substr(i, str2.length()) != str2) {
                return false;
            }
        }
        return true;
    }

    // 计算最大公约数
    static int gcd(int x, int y) {
        while (y) {
            if (x % y == 0) {
                return y;
            }
            auto t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
};

int main() {
    std::cout << Solution().gcdOfStrings("ABCABC", "ABC") << std::endl;
    std::cout << Solution().gcdOfStrings("ABABAB", "ABAB") << std::endl;
    std::cout << Solution().gcdOfStrings("LEET", "CODE") << std::endl;
    std::string s1 = "TAUXXTAUXXTAUXXTAUXXTAUXX";
    std::string s2 = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX";
    std::cout << Solution().gcdOfStrings(s1, s2) << std::endl;
    return 0;
}