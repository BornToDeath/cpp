//
// Created by boss on 2023/5/11.
//

#include <string>

using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            while (i < j && !isalnum(s[i])) {
                ++i;
            }
            while (i < j && !isalnum(s[j])) {
                --j;
            }
            if (std::tolower(s[i]) != std::tolower(s[j])) {
                return false;
            }
        }
        return true;
    }
};