//
// Created by lixiaoqing on 2022/8/21.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        /**
         * 方法1：递归，不AC，超出时间限制
         */
//        if (s.empty()) {
//            return 0;
//        }
//        return decoding(s, 0);

        /**
         * 方法2：动态规划
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        int len = s.length();
//        std::vector<int> dp(len + 1, 0);
//        dp[0] = 1;
//        for (int i = 0; i < len; ++i) {
//            if (s[i] != '0') {
//                dp[i + 1] = dp[i];
//            }
//            if (i > 0 && s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + s[i] - '0') <= 26) {
//                dp[i + 1] += dp[i - 1];
//            }
//        }
//        return dp[len];

        /**
         * 方法3：在方法2的基础上对空间进行优化
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int len = s.length();
        int m = 0, n = 1, ans = 0;
        for (int i = 0; i < len; ++i) {
            ans = s[i] == '0' ? 0 : n;
            if (i > 0 && s[i - 1] != '0' && ((s[i - 1] - '0') * 10 + s[i] - '0') <= 26) {
                ans += m;
            }
            m = n;
            n = ans;
        }
        return ans;
    }

private:
    int decoding(std::string s, int pos) {
        if (pos >= s.length()) {
            return 1;
        } else if (s[pos] == '0') {
            return 0;
        }
        int ans = decoding(s, pos + 1);
        if (pos + 1 < s.length()) {
            int num = (s[pos] - '0') * 10 + s[pos + 1] - '0';
            if (num <= 26) {
                ans += decoding(s, pos + 2);
            }
        }
        return ans;
    }
};

int main() {
    std::cout << Solution().numDecodings("1237") << std::endl;
    std::cout << Solution().numDecodings("10") << std::endl;
    return 0;
}