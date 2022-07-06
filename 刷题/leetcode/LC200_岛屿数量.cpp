//
// Created by lixiaoqing on 2022/7/6.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        /**
         * 方法1：DFS
         */
//        if (grid.empty()) {
//            return 0;
//        }
//        int count = 0;
//        int rows = grid.size(), cols = grid[0].size();
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                if (grid[i][j] == '1') {
//                    ++count;
//                    reset(grid, i, j);
//                }
//            }
//        }
//        return count;

        /**
         * 方法2：BFS
         */
        if (grid.empty()) {
            return 0;
        }
        int count = 0;
        int rows = grid.size(), cols = grid[0].size();
        std::queue<std::pair<int, int>> queue;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '0') {
                    continue;
                }
                ++count;
                grid[i][j] = '0';
                queue.emplace(i, j);
                // 需要注意的是：必须在入队列之前对元素赋0，否则存在同一元素重复入队列的问题。
                // 例如：grid = {{1,1}, {1,1}}，grid[1][1]此元素有重复入队列的问题
                while (!queue.empty()) {
                    auto pair = queue.front();
                    queue.pop();
                    int row = pair.first, col = pair.second;
//                    grid[row][col] = '0';
                    if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                        queue.emplace(row - 1, col);
                        grid[row - 1][col] = '0';
                    }
                    if (row + 1 < rows && grid[row + 1][col] == '1') {
                        queue.emplace(row + 1, col);
                        grid[row + 1][col] = '0';
                    }
                    if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                        queue.emplace(row, col - 1);
                        grid[row][col - 1] = '0';
                    }
                    if (col + 1 < cols && grid[row][col + 1] == '1') {
                        queue.emplace(row, col + 1);
                        grid[row][col + 1] = '0';
                    }
                }
            }
        }
        return count;
    }

private:
    void reset(std::vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        reset(grid, i - 1, j);
        reset(grid, i + 1, j);
        reset(grid, i, j - 1);
        reset(grid, i, j + 1);
    }
};

int main() {
    std::vector<std::vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };
    std::cout << Solution().numIslands(grid) << std::endl;
    return 0;
}