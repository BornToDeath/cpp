//
// Created by lixiaoqing on 2023/1/10.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto end = s.find_last_not_of(' ');
        auto begin = s.find_last_of(' ', end);
        return end == std::string::npos ? 0 : end - begin;
    }
};

int main() {
    std::cout << Solution().lengthOfLastWord("Hello World") << std::endl;
    std::cout << Solution().lengthOfLastWord("Hello World  ") << std::endl;
    std::cout << Solution().lengthOfLastWord("  luffy is still joyboy  ") << std::endl;
    std::cout << Solution().lengthOfLastWord("        ") << std::endl;
    std::cout << Solution().lengthOfLastWord("nihao") << std::endl;
    return 0;
}