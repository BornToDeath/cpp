//
// Created by lixiaoqing on 2023/1/30.
//

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            while (i < j && LETTERS.count(s[i]) == 0) {
                ++i;
            }
            while (i < j && LETTERS.count(s[j]) == 0) {
                --j;
            }
            if (i < j) {
                std::swap(s[i], s[j]);
            }
        }
        return s;
    }

private:
    const std::unordered_set<char> LETTERS = {
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
    };
};

int main() {
    std::cout << Solution().reverseVowels("hello") << std::endl;
    std::cout << Solution().reverseVowels("leetcode") << std::endl;
    return 0;
}