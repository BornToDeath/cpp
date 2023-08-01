//
// Created by lixiaoqing on 2023/8/1.
//

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        /*
         * 时间复杂度 O(n), 空间复杂度 O(M), 其中 |M|=26
         */
        std::vector<int> dp(26, 0);
        // 预先计算各个字母的最大下标
        for (int i = 0; i < s.length(); ++i) {
            dp[s[i] - 'a'] = i;
        }
        std::vector<int> ans;
        for (int i = 0, start = 0, end = 0; i < s.length(); ++i) {
            end = std::max(end, dp[s[i] - 'a']);
            if (i == end) {  // 是否超出当前区间的右边界
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};

int main() {
    std::string s = "ababcbacadefegdehijhklij";
//    s = "eccbbbbdec";
    auto v = Solution().partitionLabels(s);
    for (auto n: v) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
    return 0;
}