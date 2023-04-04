//
// Created by lixiaoqing on 2023/4/4.
//

#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int minPrice = prices[0], maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            maxProfit = std::max(maxProfit, prices[i] - minPrice);
            minPrice = std::min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};