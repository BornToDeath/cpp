//
// Created by lixiaoqing on 2023/2/1.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        /**
         * 时间复杂度 O(m + n) ，空间复杂度 O(1)
         */
        if (s.length() > t.length()) {
            return false;
        }
        int i = 0;
        for (int j = 0; i < s.length() && j < t.length(); ++j) {
            if (s[i] == t[j]) {
                ++i;
            }
        }
        return i == s.length();
    }
};