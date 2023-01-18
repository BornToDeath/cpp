//
// Created by lixiaoqing on 2022/8/24.
//

#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (auto c: columnTitle) {
            ans = ans * 26 + (c - 'A' + 1);
        }
        return ans;
    }
};