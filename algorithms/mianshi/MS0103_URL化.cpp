//
// Created by lixiaoqing on 2023/6/12.
//

#include <string>

using std::string;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        std::string ans;
        for (int i = 0; i < length; ++i) {
            auto c = S.at(i);
            if (c == ' ') {
                ans.append("%20");
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};