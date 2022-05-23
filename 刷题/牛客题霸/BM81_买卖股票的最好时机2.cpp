//
// Created by lixiaoqing on 2022/5/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int> &prices) {
        /**
         * 贪心思想。只要一段区间内价格是递增的，那么这段区间的差值就是我们可以有的收益。
         */
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

int main() {
    std::vector<int> prices = {1, 2, 3, 4, 5};
    std::cout << Solution().maxProfit(prices) << std::endl;
    return 0;
}