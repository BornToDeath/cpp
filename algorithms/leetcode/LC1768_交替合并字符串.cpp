//
// Created by lixiaoqing on 2023/6/28.
//

#include <string>

using std::string;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string ans;
        int i = 0;
        while (i < word1.length() && i < word2.length()) {
            ans.push_back(word1.at(i));
            ans.push_back(word2.at(i));
            ++i;
        }
        if (i < word1.length()) {
            ans.append(word1.substr(i));
        }
        if (i < word2.length()) {
            ans.append(word2.substr(i));
        }
        return ans;
    }
};