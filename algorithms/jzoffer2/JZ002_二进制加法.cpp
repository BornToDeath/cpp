//
// Created by lixiaoqing on 2023/4/11.
//

#include <string>

using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        /*
         * 方法1: 先反转再求和
         * 时间复杂度 O(m + n) , 空间复杂度 O(1)
         */
//        int carry = 0;
//        std::string ans;
//        std::reverse(a.begin(), a.end());
//        std::reverse(b.begin(), b.end());
//        for (int i = 0; i < a.length() || i < b.length(); ++i) {
//            int n1 = i < a.length() ? a[i] - '0' : 0;
//            int n2 = i < b.length() ? b[i] - '0' : 0;
//            auto sum = n1 + n2 + carry;
//            ans.push_back(sum % 2 + '0');
//            carry = sum / 2;
//        }
//        if (carry) {
//            ans.push_back('1');
//        }
//        std::reverse(ans.begin(), ans.end());
//        return ans;

        /*
         * 方法2: 倒序求和
         * 时间复杂度 O(m + n) , 空间复杂度 O(1)
         */
        std::string ans;
        for (int i = a.length() - 1, j = b.length() - 1, carry = 0; i >= 0 || j >= 0 || carry > 0; --i, --j) {
            int n1 = i >= 0 ? a[i] - '0' : 0;
            int n2 = j >= 0 ? b[j] - '0' : 0;
            const auto sum = n1 + n2 + carry;
            ans.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
