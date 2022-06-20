//
// Created by lixiaoqing on 2022/6/20.
//

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int min = prices[0], max = 0;
        for (int i = 1; i < prices.size(); ++i) {
            min = std::min(min, prices[i]);
            max = std::max(max, prices[i] - min);
        }
        return max;
    }
};