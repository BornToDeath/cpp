//
// Created by lixiaoqing on 2022/3/29.
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
        int max = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - minPrice > max) {
                max = prices[i] - minPrice;
            }
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
        }
        return max;
    }
};

int main() {
//    std::vector<int> prices = {8, 9, 2, 5, 4, 7, 1};
//    std::vector<int> prices = {2, 4, 1};
    std::vector<int> prices = {3, 2, 1};
    std::cout << Solution().maxProfit(prices) << std::endl;
    return 0;
}