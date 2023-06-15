//
// Created by lixiaoqing on 2023/6/15.
//

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(), n = p.length();
        if (m < n) {
            return {};
        }

        std::vector<int> ans;
        std::vector<int> dp(26, 0);
        for (int i = 0; i < n; ++i) {
            ++dp[s[i] - 'a'];
            --dp[p[i] - 'a'];
        }
        if (check(dp)) {
            ans.push_back(0);
        }
        for (int i = n; i < m; ++i) {
            int x = s[i] - 'a';
            int y = s[i - n] - 'a';
            ++dp[x];
            --dp[y];
            if (check(dp)) {
                ans.push_back(i - n + 1);
            }
        }
        return ans;
    }

private:
    bool check(const std::vector<int> &arr) {
        return std::all_of(arr.begin(), arr.end(), [](int n) { return n == 0; });
    }
};

int main() {
//    auto ans = Solution().findAnagrams("cbaebabacd", "abc");
    auto ans = Solution().findAnagrams("abab", "ab");
    for (auto n: ans) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
    return 0;
}