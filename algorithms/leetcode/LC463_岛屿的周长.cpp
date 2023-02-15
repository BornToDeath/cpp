//
// Created by lixiaoqing on 2023/2/14.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        /**
         * 方法1：遍历
         * 时间复杂度 O(mn) ，空间复杂度 O(1)
         */
//        if (grid.empty()) {
//            return 0;
//        }
//        int ans = 0;
//        int rows = grid.size(), cols = grid[0].size();
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                if (grid[i][j] == 0) {
//                    continue;
//                }
//                if (i == 0 || grid[i - 1][j] == 0) {
//                    ++ans;
//                }
//                if (i == rows - 1 || grid[i + 1][j] == 0) {
//                    ++ans;
//                }
//                if (j == 0 || grid[i][j - 1] == 0) {
//                    ++ans;
//                }
//                if (j == cols - 1 || grid[i][j + 1] == 0) {
//                    ++ans;
//                }
//            }
//        }
//        return ans;

        /**
         * 方法2：DFS
         * 时间复杂度 O(mn) ，空间复杂度 O(mn)
         */
        if (grid.empty()) {
            return 0;
        }
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }

private:
    int dfs(vector<vector<int>> &grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return 1;
        }
        if (grid[x][y] == -1) {
            return 0;
        }
        int ans = 0;
        grid[x][y] = -1;
        for (int i = 0; i < 4 ; ++i) {
            ans += dfs(grid, x + dx[i], y + dy[i]);
        }
        return ans;
    }

private:
    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};
};

int main() {
    std::vector<std::vector<int>> grid = {
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0}
    };
    std::cout << Solution().islandPerimeter(grid) << std::endl;
    return 0;
}