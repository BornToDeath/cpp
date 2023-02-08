//
// Created by lixiaoqing on 2023/2/8.
//

#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        /**
         * 方法：双指针
         * 时间复杂度 O(max(len1, len2)) ，空间复杂度 O(1)
         */
        std::string ans;
        int sum = 0;
        for (int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0 || sum > 0; --i, --j) {
            if (i >= 0) {
                sum += num1[i] - '0';
            }
            if (j >= 0) {
                sum += num2[j] - '0';
            }
            ans.push_back(sum  % 10 + '0');
            sum = sum / 10;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};