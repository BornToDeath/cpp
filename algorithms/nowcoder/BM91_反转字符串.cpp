//
// Created by lixiaoqing on 2022/5/7.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串
     * @return string字符串
     */
    string solve(string str) {
        /**
         * 方法1：使用 std::reverse
         */
//        std::reverse(str.begin(), str.end());
//        return str;

        /**
         * 方法2：使用额外空间
         */
//        std::string res;
//        for (int i = str.length() - 1; i >= 0; --i) {
//            res.push_back(str[i]);
//        }
//        return res;

        /**
         * 方法3：双指针，原地反转
         */
        int len = str.length();
        for (int i = 0; i < len / 2; ++i) {
            auto temp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = temp;
        }
        return str;
    }
};

int main() {
    std::cout << Solution().solve("absjdnsfjas") << std::endl;
    return 0;
}