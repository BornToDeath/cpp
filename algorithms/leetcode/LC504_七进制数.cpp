//
// Created by lixiaoqing on 2023/3/3.
//

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        bool neg = num < 0;
        num = abs(num);
        std::string ans;
        while (num) {
            ans.push_back(num % 7 + '0');
            num /= 7;
        }
        if (neg) {
            ans.push_back('-');
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    std::cout << Solution().convertToBase7(111) << std::endl;
    std::cout << Solution().convertToBase7(-111) << std::endl;
    return 0;
}