//
// Created by lixiaoqing on 2022/4/14.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        /**
         * 方法1：利用 string.substr()
         */
//        if (str.empty()) {
//            return {};
//        }
//        n %= str.size();
//        return str.substr(n) + str.substr(0, n);

        /**
         * 方法2：翻转字符串
         */
        if (str.empty()) {
            return {};
        }
        n %= str.size();
        // 先翻转前半部分
        std::reverse(str.begin(), str.begin() + n);
        // 再翻转后半部分
        std::reverse(str.begin() + n, str.end());
        // 再整体翻转
        std::reverse(str.begin(), str.end());
        return str;
    }
};

int main() {
    const std::string str = "abcdefg";
    std::cout << Solution().LeftRotateString(str, 10) << std::endl;
    return 0;
}