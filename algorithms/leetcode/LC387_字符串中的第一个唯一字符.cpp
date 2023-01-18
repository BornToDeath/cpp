//
// Created by lixiaoqing on 2022/9/6.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        /**
         * 方法1：借助 std::unordered_map
         * 时间复杂度 O(n) ，空间复杂度 O(k) ，其中 k<=26
         */
//        std::unordered_map<char, int> map;
//        for (auto ch: s) {
//            ++map[ch];
//        }
//        for (int i = 0; i < s.length(); ++i) {
//            if (map[s[i]] == 1) {
//                return i;
//            }
//        }
//        return -1;

        /**
         * 方法2：借助数组
         * 时间复杂度 O(n) ，空间复杂度 O(k) ，其中 k=26
         */
        int arr[26]{};
        for (auto ch: s) {
            ++arr[ch - 'a'];
        }
        for (int i = 0; i < s.length(); ++i) {
            if (arr[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    std::string str = "loveleetcode";
    std::cout << Solution().firstUniqChar(str) << std::endl;
    return 0;
}