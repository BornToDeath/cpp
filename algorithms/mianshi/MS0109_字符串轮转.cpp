//
// Created by lixiaoqing on 2023/6/1.
//

#include <string>

using std::string;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        return (s1 + s1).find(s2) != s1.npos;
    }
};