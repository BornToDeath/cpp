//
// Created by lixiaoqing on 2023/6/1.
//

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        /*
         * 方法1: 顺序比较
         * 时间复杂度 O(max(n + m)) , 空间复杂度 O(1)
         */
        const int len1 = first.length(), len2 = second.length();
        for (int i = 0; i < len1 || i < len2; ++i) {
            if (i >= len1 || i >= len2 || first[i] != second[i]) {
                return equal(first, i + 1, second, i) ||
                       equal(first, i, second, i + 1) ||
                       equal(first, i + 1, second, i + 1);
            }
        }
        return true;

        /*
         * 方法2: 双指针
         * 参考: https://leetcode.cn/problems/one-away-lcci/solution/by-ac_oier-7ml0/
         * 时间复杂度 O(max(m, n)) , 空间复杂度 O(1)
         */
//        int m = first.length(), n = second.length();
//        if (abs(m - n) > 1) {
//            return false;
//        }
//        if (m > n) {
//            return oneEditAway(second, first);
//        }
//        int i = 0, j = 0, count = 0;
//        while (i < m && j < n && count <= 1) {
//            if (first[i] == second[j]) {
//                ++i;
//                ++j;
//            } else {
//                if (m == n) {
//                    ++i;
//                    ++j;
//                    ++count;
//                } else {
//                    ++j;
//                    ++count;
//                }
//            }
//        }
//        return count <= 1;
    }

private:
    bool equal(const std::string &s1, int i, const std::string &s2, int j) {
        while (i < s1.length() && j < s2.length()) {
            if (s1[i] != s2[j]) {
                return false;
            }
            ++i, ++j;
        }
        if (i < s1.length() || j < s2.length()) {
            return false;
        }
        return true;
    }
};

int main() {
    std::cout << Solution().oneEditAway("abcd", "abce") << std::endl;
    return 0;
}