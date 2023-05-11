//
// Created by boss on 2023/5/11.
//

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j && s[i] == s[j]) {
            ++i, --j;
        }
        if (i >= j) {
            return true;
        }
        return valid(s, i + 1, j) || valid(s, i, j - 1);
    }

private:
    bool valid(const std::string &s, int i, int j) {
        while (i < j && s[i] == s[j]) {
            ++i, --j;
        }
        return i >= j;
    }
};

int main() {
    std::string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    std::cout << Solution().validPalindrome(s) << std::endl;
    return 0;
}