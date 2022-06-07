//
// Created by lixiaoqing on 2022/6/7.
//

#include <vector>

class Robot {
public:
    int countWays(int x, int y) {
        std::vector<int> dp(x, 1);
        for (int i = 1; i < y; ++i) {
            for (int j = 1; j < x; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[x - 1];
    }
};