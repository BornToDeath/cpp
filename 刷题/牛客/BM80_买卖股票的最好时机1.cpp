//
// Created by lixiaoqing on 2022/10/18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int buy = prices[0], max = 0;
        for (int i = 1; i < prices.size(); ++i) {
            max = std::max(prices[i] - buy, max);
            buy = std::min(buy, prices[i]);
        }
        return max;
    }
};

int main() {
    std::vector<int> prices = {8, 9, 2, 5, 4, 7, 1};
    std::cout << Solution().maxProfit(prices) << std::endl;
    return 0;
}