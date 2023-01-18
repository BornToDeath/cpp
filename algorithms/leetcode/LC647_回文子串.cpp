//
// Created by lixiaoqing on 2022/7/28.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        /**
         * 方法1：元素之间插入 '#' 。
         * 时间复杂度 O(n^2) ，空间复杂度 O(n)
         */
//        int count = 0;
//        std::string str("#");
//        for (auto ch: s) {
//            str.push_back(ch);
//            str.push_back('#');
//        }
//        for (int i = 1; i < str.length() - 1; ++i) {
//            int l = i - 1, r = i + 1;
//            while (l >= 0 && r < str.length() && str[l] == str[r]) {
//                if (str[l] == '#') {
////                    printf("%s\n", str.substr(l, r - l + 1).c_str());
//                    ++count;
//                }
//                --l;
//                ++r;
//            }
//        }
//        return count;

        /**
         * 方法2：在方法1的基础上进行优化
         * 时间复杂度 O(n^2) ，空间复杂度 O(1)
         */
        int count = 0;
        for (int i = 0; i < s.length() * 2 - 1; ++i) {
            int l = i / 2, r = l + i % 2;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                ++count;
                --l;
                ++r;
            }
        }
        return count;

    }
};

int main() {
    std::cout << Solution().countSubstrings("abba") << std::endl;
    std::cout << Solution().countSubstrings("abbc") << std::endl;
    return 0;
}