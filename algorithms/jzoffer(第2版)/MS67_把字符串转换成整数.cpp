//
// Created by lixiaoqing on 2023/4/10.
//

#include <string>
#include <sstream>
#include <iostream>

using std::string;

class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        while (i < str.length() && str[i] == ' ') {
            ++i;
        }
        int pos = 1;
        if (i < str.length() && (str[i] == '+' || str[i] == '-')) {
            pos = str[i] == '+' ? 1 : -1;
            ++i;
        }
        int ans = 0;
        while (i < str.length() && isnumber(str[i])) {
            if (pos == 1 && ans > (INT_MAX - (str[i] - '0') * pos) / 10) {
                return INT_MAX;
            }
            if (pos == -1 && ans < (INT_MIN - (str[i] - '0') * pos) / 10) {
                return INT_MIN;
            }
            ans = ans * 10 + (str[i] - '0') * pos;
            ++i;
        }
        return ans;
    }
};

int main() {
    std::cout << Solution().strToInt("-42") << std::endl;
    return 0;
}