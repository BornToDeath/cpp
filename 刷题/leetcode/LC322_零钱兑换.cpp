//
// Created by lixiaoqing on 2022/7/23.
//

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> &arr) {
    for (auto num: arr) {
        printf("%d, ", num);
    }
    printf("\n");
}

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (coins.empty()) {
            return -1;
        }
        std::sort(coins.begin(), coins.end());
        // 初始化各元素初值为 amount + 1（代表不可能存在的情况）
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto num: coins) {
                if (num > i) {
                    break;
                }
                // 状态转移方程
                dp[i] = std::min(dp[i], dp[i - num] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main() {
    std::vector<int> coins = {1, 2, 5};
    std::cout << Solution().coinChange(coins, 11) << std::endl;
    return 0;
}
