//
// Created by lixiaoqing on 2022/3/29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param grid int整型vector<vector<>>
     * @return int整型
     */
    int maxValue(vector<vector<int> > &grid) {
        if (grid.empty()) {
            return 0;
        }
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                } else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};