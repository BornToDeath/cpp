//
// Created by lixiaoqing on 2022/8/23.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        /**
         * 贪心思想，只要一段时间内价格是递增的，那么这段区间内的差值就是我们可以有的收益
         */
        int max = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                max += prices[i] - prices[i - 1];
            }
        }
        return max;
    }
};

int main() {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << Solution().maxProfit(prices) << std::endl;
    return 0;
}
