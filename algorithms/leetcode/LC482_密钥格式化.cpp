//
// Created by lixiaoqing on 2023/2/15.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        /**
         * 方法：从后向前遍历
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        std::string ans;
        int pos = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '-') {
                continue;
            }
            auto c = s[i];
            if (c >= 'a' && c <= 'z') {
                c += 'A' - 'a';
            }
            ans.push_back(c);
            ++pos;
            if (pos % k == 0) {
                ans.push_back('-');
            }
        }
        if (!ans.empty() && ans.back() == '-') {
            ans.pop_back();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    std::cout << Solution().licenseKeyFormatting("5F3Z-2e-9-w", 4) << std::endl;
    std::cout << Solution().licenseKeyFormatting("2-5g-3-J", 2) << std::endl;
    std::cout << Solution().licenseKeyFormatting("--a-a-a-a--", 2) << std::endl;

    return 0;
}