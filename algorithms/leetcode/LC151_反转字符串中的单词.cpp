//
// Created by lixiaoqing on 2023/6/29.
//

#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string reverseWords(string s) {
        std::string ans;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                continue;
            }
            int j = i - 1;
            while (j >= 0 && s[j] != ' ') {
                --j;
            }
            ans.append(s.substr(j + 1, i - j)).push_back(' ');
            i = j;
        }
        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }

};

int main() {
    std::cout << "["
              << Solution().reverseWords("  hello world  ")
              << "]"
              << std::endl;
    return 0;
}