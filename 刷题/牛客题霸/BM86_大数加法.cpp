//
// Created by lixiaoqing on 2022/5/24.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        if (s.empty()) {
            return t;
        }
        if (t.empty()) {
            return s;
        }
        std::string res;
        int carry = 0;
        std::reverse(s.begin(), s.end());
        std::reverse(t.begin(), t.end());
        for (int i = 0; i < s.length() || i < t.length(); ++i) {
            int num1 = 0, num2 = 0;
            if (i < s.length()) {
                num1 = s[i] - '0';
            }
            if (i < t.length()) {
                num2 = t[i] - '0';
            }
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            sum %= 10;
            res.append(std::to_string(sum));
        }
        if (carry == 1) {
            res.append("1");
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    std::string str1 = "110";
    std::string str2 = "990";
    std::cout << Solution().solve(str1, str2) << std::endl;
    return 0;
}