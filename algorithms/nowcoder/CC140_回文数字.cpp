//
// Created by lixiaoqing on 2022/6/6.
//

#include <iostream>
#include <string>

class Solution {
public:
    /**
     *
     * @param x int整型
     * @return bool布尔型
     */
    bool isPalindrome(int x) {
        /**
         * 方法1：
         */
//        std::string s1 = std::to_string(x);
//        auto s2 = s1;
//        std::reverse(s2.begin(), s2.end());
//        return s1 == s2;

        /**
         * 方法2：
         */
        if (x < 0) {
            return false;
        }
        int x2 = 0, temp = x;
        while (x) {
            x2 = x2 * 10 + x % 10;
            x /= 10;
        }
        return x2 == temp;
    }
};

int main() {
    std::cout << Solution().isPalindrome(1) << std::endl;
    return 0;
}