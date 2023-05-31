//
// Created by lixiaoqing on 2023/5/31.
//

#include <iostream>
#include <string>
#include <unordered_set>

using std::string;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        /*
         * 方法1: 哈希表
         */
        std::unordered_set<char> _set;
        for (auto c : s) {
            if (_set.count(c)) {
                _set.erase(c);
            } else {
                _set.insert(c);
            }
        }
        return _set.size() <= 1;
    }
};

int main() {
    std::cout << Solution().canPermutePalindrome("tactcoa") << std::endl;
    return 0;
}