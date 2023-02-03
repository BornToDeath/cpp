//
// Created by lixiaoqing on 2023/2/2.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        /**
         * 方法1：使用 std::ostringstream
         */
//        std::ostringstream oss;
//        oss << std::hex << num;
//        return oss.str();

        /**
         * 方法2：位运算
         */
        const std::vector<char> dp = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        std::string s;
        unsigned int n = num;  // 转为无符号数进行位运算
        do {
            s.push_back(dp[n & 0xf]);
            n >>= 4;
        } while (n);
        std::reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    std::cout << Solution().toHex(0) << std::endl;
    std::cout << Solution().toHex(10) << std::endl;
    std::cout << Solution().toHex(128) << std::endl;
    std::cout << Solution().toHex(-1) << std::endl;
    return 0;
}