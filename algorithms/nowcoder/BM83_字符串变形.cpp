//
// Created by lixiaoqing on 2022/5/9.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string trans(string s, int n) {
        // 1. 先反转整个字符串
        std::reverse(s.begin(), s.end());

        // 2. 再反转每个单词
//        std::string::size_type start = 0;
//        while (true) {
//            start = s.find_first_not_of(' ', start);
//            auto end = s.find_first_of(' ', start);
//            if (end == std::string::npos) {
//                break;
//            }
//            std::reverse(s.begin() + start, s.begin() + end);
//            start = end;
//        }
//        std::reverse(s.begin() + start, s.end());
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                continue;
            }
            int j = i;
            while (j < n && s[j] != ' ') {
                ++j;
            }
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }

        // 3. 再转大写
        std::transform(s.begin(), s.end(), s.begin(), [](char ch) -> char {
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
                return (ch < 'a') ? ch + 32 : ch - 32;
            }
            return ch;
        });
        return s;
    }
};

int main() {
    std::string str = "you are the APPLE      of my EYE.    ";
    std::cout << Solution().trans(str, str.length()) << std::endl;
    return 0;
}