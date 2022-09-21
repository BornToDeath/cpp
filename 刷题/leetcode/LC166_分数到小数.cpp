//
// Created by lixiaoqing on 2022/9/16.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        /**
         * 方法：竖式除法计算
         * 参考：https://leetcode.cn/problems/fraction-to-recurring-decimal/solution/gong-shui-san-xie-mo-ni-shu-shi-ji-suan-kq8c4/
         */
        long num = numerator, den = denominator;
        if (num % denominator == 0) {
            return std::to_string(num / den);
        }
        std::string ans;
        if (num < 0 ^ den < 0) {
            ans.push_back('-');
        }
        // 整数部分
        num = std::abs(num);
        den = std::abs(den);
        ans += std::to_string(num / den);
        ans.push_back('.');
        num %= den;
        // 小数部分
        std::unordered_map<long, int> unmap;
        int pos = ans.length();
        while (num != 0) {
            unmap[num] = pos;
            num *= 10;
            ans += std::to_string(num / den);
            num %= den;
            // 如果当前余数之前出现过，则将循环部分用括号括起来
            if (unmap.count(num) != 0) {
                // 循环部分
                auto index = unmap[num];
                ans = ans.substr(0, index) + "(" + ans.substr(index) + ")";
                break;
            }
            pos++;
        }
        return ans;
    }
};

int main() {
//    std::cout << Solution().fractionToDecimal(1, 2) << std::endl;
//    std::cout << Solution().fractionToDecimal(7, -12) << std::endl;
//    std::cout << Solution().fractionToDecimal(10, 2) << std::endl;
    std::cout << Solution().fractionToDecimal(4, 333) << std::endl;
    std::cout << Solution().fractionToDecimal(1, 6) << std::endl;
//    std::cout << std::setprecision(10) << 4.0 / 3333 << std::endl;
//    std::cout << std::setprecision(20) << 0.0001200012 * 33333 << std::endl;
//    std::cout << INT_MAX * 1.0 / INT_MIN << std::endl;
    return 0;
}