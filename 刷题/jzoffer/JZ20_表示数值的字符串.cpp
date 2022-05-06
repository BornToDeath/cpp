//
// Created by lixiaoqing on 2022/5/6.
//

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return bool布尔型
     */
    bool isNumeric(string str) {
        /**
         * 方法1：对字符串分别校验是否是整数、小数、科学技术数
         */
        // 去除首尾空格
        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1);
        if (str.empty()) {
            return false;
        }
        return isInteger(str) || isDecimal(str) || isScientificNumber(str);

        /**
         * 方法2：正则表达式
         */
//        std::regex regex("^[+-]?(\\d*\\.\\d+|\\d+(\\.\\d*)?)(?:[eE][+-]?\\d+)?$");
//        return std::regex_match(str, regex);
    }

private:
    /**
     * 判断字符串是否是整数
     * @param str 非空字符串
     * @return
     */
    bool isInteger(const std::string &str) {
        if (str.empty()) {
            return false;
        }
        int pos = 0;
        if (str[pos] == '+' || str[pos] == '-') {
            ++pos;
            if (pos >= str.length()) {
                return false;
            }
        }
        while (pos < str.length()) {
            if (str[pos] >= '0' && str[pos] <= '9') {
                ++pos;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    /**
     * 判断字符串是否是小数
     * @param str 非空字符串
     * @return
     */
    bool isDecimal(const std::string &str) {
        if (str.empty()) {
            return false;
        }
        int pos = 0;
        if (str[pos] == '+' || str[pos] == '-') {
            ++pos;
            if (pos >= str.length()) {
                return false;
            }
        }
        if (str[pos] == '.') {
            ++pos;
            if (pos >= str.length()) {
                return false;
            }
            while (pos < str.length()) {
                if (str[pos] >= '0' && str[pos] <= '9') {
                    ++pos;
                    continue;
                }
                return false;
            }
            return true;
        }
        while (pos < str.length() && str[pos] >= '0' && str[pos] <= '9') {
            ++pos;
        }
        if (pos < str.length() && str[pos] == '.') {
            ++pos;
            while (pos < str.length()) {
                if (str[pos] >= '0' && str[pos] <= '9') {
                    ++pos;
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        } else {
            return false;
        }
    }

    /**
     * 判断是否是科学计数法数字
     * @param str 非空字符串
     * @return
     */
    bool isScientificNumber(const std::string &str) {
        auto it = str.find_first_of('e');
        if (it == string::npos) {
            it = str.find_first_of('E');
        }
        auto str1 = str.substr(0, it);
        if (isInteger(str1) || isDecimal(str1)) {
            if (it == string::npos) {
                return true;
            }
            auto str2 = str.substr(it + 1);
            return isInteger(str2);
        } else {
            return false;
        }
    }
};


int main() {
    std::cout << boolalpha;
    const auto str = "+";
    std::cout << Solution().isNumeric(str) << std::endl;
    return 0;
}