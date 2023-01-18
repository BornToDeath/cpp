//
// Created by lixiaoqing on 2022/8/10.
//

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> MAP = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i != s.length() - 1 && MAP[s[i]] < MAP[s[i + 1]]) {
                num -= MAP[s[i]];
            } else {
                num += MAP[s[i]];
            }
        }
        return num;
    }
};

int main() {
    std::cout << Solution().romanToInt("LIVIII") << std::endl;
    return 0;
}