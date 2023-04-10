//
// Created by lixiaoqing on 2023/3/27.
//

#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string reverseWords(string s) {
        /*
         * 方法: 从后向前逐个单词翻转
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        std::string ans;
        for (int i = s.length() - 1; i >= 0;) {
            i = s.find_last_not_of(' ', i);
            if (i == std::string::npos) {
                break;
            }
            int j = s.find_last_of(' ', i);
            ans.append(s.substr(j + 1, i - j) + " ");
            i = j;
        }
        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};

int main() {
    std::cout << Solution().reverseWords("Hello") << std::endl;
    std::cout << Solution().reverseWords("Hello world.") << std::endl;
    std::cout << Solution().reverseWords("Hello    ") << std::endl;
    std::cout << Solution().reverseWords("    Hello    ") << std::endl;
    std::cout << Solution().reverseWords("    ") << std::endl;
    return 0;
}