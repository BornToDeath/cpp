//
// Created by lixiaoqing on 2023/3/28.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        /*
         * 方法1: 暴力统计, 不 AC , 时间超限
         * 时间复杂度 O(6 ^ n) , 空间复杂度 O(n)
         */
//        std::vector<double> ans(5 * n + 1);
//        const double all = pow(6, n);
//        for (int i = n; i <= 6 * n; ++i) {
//            ans[i - n] = permutations(n, i) / all;
//        }
//        return ans;

        /*
         * 方法2: 动态规划: f(n, x) = f(n - 1, x - i) * (1 / 6), i: 1->6
         * 时间复杂度 O(n^2) , 空间复杂度 O(n)
         */
        vector<double> dp(6, 1.0 / 6.0);
        // i 表示当前共有几个骰子
        for (int i = 2; i <= n; i++) {
            vector<double> tmp(5 * i + 1, 0);
            // j 表示之前所有骰子掷出的总点数
            for (int j = 0; j < dp.size(); j++) {
                // k 表示当前骰子掷出的点数
                for (int k = 0; k < 6; k++) {
                    // j + k 表示当前的总点数 (之前的总点数 + 当前点数), 注: 所有点数和都从0开始, 方便计算。
                    // 如: 如果 3 个骰子, 点数和应为 3-18 , 但是为方便计算，将其向前偏移 3, 范围为: 0-15, 即 0 表示原来的 3
                    tmp[j + k] += dp[j] * 1.0 / 6.0;
                }
            }
            dp = tmp;
        }
        return dp;
    }

private:
    int permutations(int n, int num) {
        if (n == 1) {
            return num >= 1 && num <= 6 ? 1 : 0;
        }
        int count = 0;
        for (int i = 1; i <= 6; ++i) {
            count += permutations(n - 1, num - i);
        }
        return count;
    }
};

int main() {
    // [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
    auto ans = Solution().dicesProbability(2);
    for (auto n: ans) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
    return 0;
}