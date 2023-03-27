//
// Created by lixiaoqing on 2023/3/27.
//

#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if (s.empty() || n <= 0 || n >= s.length()) {
            return s;
        }
        std::reverse(s.begin(), s.begin() + n);
        std::reverse(s.begin() + n, s.end());
        std::reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    std::cout << Solution().reverseLeftWords("abcdefg", 2) << std::endl;
    std::cout << Solution().reverseLeftWords("abcdefg", 5) << std::endl;
    return 0;
}