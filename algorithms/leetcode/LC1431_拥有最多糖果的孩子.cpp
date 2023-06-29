//
// Created by lixiaoqing on 2023/6/29.
//

#include <vector>

using std::vector;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        std::vector<bool> ans(candies.size(), false);
        auto max = *std::max_element(candies.begin(), candies.end());
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = candies[i] >= max - extraCandies;
        }
        return ans;
    }
};