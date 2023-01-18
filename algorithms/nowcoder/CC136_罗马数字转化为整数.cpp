//
// Created by lixiaoqing on 2022/6/6.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return int整型
     */
    int romanToInt(string s) {
        const std::map<char, int> MAP = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        int sum = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i == s.length() - 1 || MAP.at(s[i]) >= MAP.at(s[i + 1])) {
                sum += MAP.at(s[i]);
            } else {
                sum -= MAP.at(s[i]);
            }
        }
        return sum;
    }
};

int main() {
    std::string str = "MCMXCVI";
    std::cout << Solution().romanToInt(str) << std::endl;
    return 0;
}