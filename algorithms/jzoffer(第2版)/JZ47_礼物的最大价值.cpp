//
// Created by lixiaoqing on 2023/3/21.
//

#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int maxValue(vector<vector<int>> &grid) {
        if (grid.empty()) {
            return 0;
        }
        const int rows = grid.size(), cols = grid[0].size();
        for (int i = 1; i < rows; ++i) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < cols; ++i) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                grid[i][j] += std::max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[rows - 1][cols - 1];
    }
};

int main() {
    std::vector<std::vector<int>> grid = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    std::cout << Solution().maxValue(grid) << std::endl;
    return 0;
}