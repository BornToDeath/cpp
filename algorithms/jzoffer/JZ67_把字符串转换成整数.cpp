//
// Created by lixiaoqing on 2022/4/8.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    int StrToInt(string s) {
        if (s.empty()) {
            return 0;
        }
        const int len = s.length();
        int pos = 0;
        // 过滤空格
        while (pos < len && s[pos] == ' ') {
            ++pos;
        }
        // 判断符号
        bool neg = false;
        if (pos < len && s[pos] == '+' || s[pos] == '-') {
            neg = s[pos] == '-';
            ++pos;
        }
        // 判断是否是无效字符
        if (pos < len && s[pos] < '0' || s[pos] > '9') {
            return 0;
        }
        // 转为整形
        long res = 0;
        while (pos < len && s[pos] >= '0' && s[pos] <= '9') {
            res = res * 10 + (s[pos] - '0');
            if (!neg && res >= INT32_MAX) {
                return INT32_MAX;
            } else if (neg && (-res) <= INT32_MIN) {
                return INT32_MIN;
            }
            ++pos;
        }
        if (neg) {
            res = -res;
        }
        return static_cast<int>(res);
    }
};

int main() {
    std::string str = "-33+-";
    std::cout << Solution().StrToInt(str) << std::endl;
    return 0;
}