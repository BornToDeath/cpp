//
// Created by lixiaoqing on 2022/9/5.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            std::swap(s[i], s[j]);
        }
    }
};