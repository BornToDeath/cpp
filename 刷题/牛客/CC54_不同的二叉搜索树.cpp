//
// Created by lixiaoqing on 2022/6/1.
//

#include <iostream>
#include <vector>

void print(const std::vector<int> &arr) {
    for (auto num: arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    /**
     *
     * @param n int整型
     * @return int整型
     */
    int numTrees(int n) {
        std::vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            if (i <= 1) {
                dp[i] = 1;
                continue;
            }
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
//        print(dp);
        return dp[n];
    }
};

int main() {
    std::cout << Solution().numTrees(3) << std::endl;
    return 0;
}