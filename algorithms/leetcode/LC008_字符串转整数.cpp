//
// Created by lixiaoqing on 2022/8/12.
//

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        /**
         * 方法1：逐个字符解析
         */
//        int ans = 0, pos = 0, len = s.length();
//        while (pos < len && s[pos] == ' ') {
//            ++pos;
//        }
//        int flag = 1;
//        if (pos < len && (s[pos] == '+' || s[pos] == '-')) {
//            flag = s[pos] == '+' ? 1 : -1;
//            ++pos;
//        }
//        if (pos < len && isnumber(s[pos])) {
//            ans = s[pos++] - '0';
//        }
//        ans *= flag;
//        const int MAX = std::numeric_limits<int>::max();
//        const int MIN = std::numeric_limits<int>::min();
//        while (pos < len && isnumber(s[pos])) {
//            int e = (s[pos++] - '0') * flag;
//            if (ans > MAX / 10 || ans == MAX / 10 && e > 7) {
//                return MAX;
//            } else if (ans < MIN / 10 || ans == MIN / 10 && e < -8) {
//                return MIN;
//            }
//            ans = ans * 10 + e;
//        }
//        return ans;

        /**
         * 方法2：使用流
         */
        std::istringstream iss(s);
        int ans = 0;
        iss >> ans;
        return ans;
    }

private:
    bool isnumber(char c) {
        return c >= '0' && c <= '9';
    }
};

int main() {
    std::cout << std::numeric_limits<int>::max() << std::endl;
    std::cout << std::numeric_limits<int>::min() << std::endl;
//    std::cout << Solution().myAtoi("-123123   sda") << std::endl;
//    std::cout << Solution().myAtoi("123123   asd") << std::endl;
//    std::cout << Solution().myAtoi("1231232117359235927") << std::endl;
    std::cout << Solution().myAtoi("91283472332") << std::endl;
    std::cout << Solution().myAtoi("-2147483649") << std::endl;
    return 0;
}