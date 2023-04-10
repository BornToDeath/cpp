//
// Created by lixiaoqing on 2023/3/22.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <array>

using std::string;

class Solution {
public:
    char firstUniqChar(string s) {
        /**
         * 方法1：借助 std::unordered_multiset ，不 AC ，时间超限
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        std::unordered_multiset<char> _set(s.begin(), s.end());
//        for (auto c: s) {
//            if (_set.count(c) == 1) {
//                return c;
//            }
//        }
//        return ' ';

        /**
         * 方法2：借助 std::array
         * 时间复杂度 O(n) ，空间复杂度 O(L) ，其中 L = 26
         */
        std::array<int, 26> arr{};
        for (auto c: s) {
            ++arr[c - 'a'];
        }
        for (auto c: s) {
            if (arr[c - 'a'] == 1) {
                return c;
            }
        }
        return ' ';
    }
};

int main() {
    std::cout << Solution().firstUniqChar("leetcode") << std::endl;
    std::cout << Solution().firstUniqChar("cc") << std::endl;
    return 0;
}