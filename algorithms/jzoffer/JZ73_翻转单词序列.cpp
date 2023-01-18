//
// Created by lixiaoqing on 2021/11/3.
//

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string ReverseSentence(string str) {
        // 1. 先反转整个字符串
        std::reverse(str.begin(), str.end());

        // 2. 再反转逐个单词
        int start = 0;
        int end = 0;
        while (end < str.length()) {
            while (end < str.length() && str[end] != ' ') {
                ++end;
            }
            std::reverse(str.begin() + start, str.begin() + end);
            ++end;
            start = end;
        }
        return str;
    }
};

int main() {
    std::string str = "You are the apple of my eye.";
    Solution solution;
    std::cout << solution.ReverseSentence(str) << std::endl;
    return 0;
}