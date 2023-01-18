//
// Created by lixiaoqing on 2022/5/17.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */
    int solve(vector<vector<char> > &grid) {
        /**
         * 方法1：深度优先遍历
         */
//        if (grid.empty()) {
//            return 0;
//        }
//        int lands = 0;
//        for (int i = 0; i < grid.size(); ++i) {
//            for (int j = 0; j < grid[0].size(); ++j) {
//                if (grid[i][j] == '1') {
//                    ++lands;
//                    dfs(grid, i, j);
//                }
//            }
//        }
//        return lands;

        /**
         * 方法2：广度优先搜索
         */
        if (grid.empty()) {
            return 0;
        }
        int lands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++lands;
                    bfs(grid, i, j);
                }
            }
        }
        return lands;
    }

private:
    /**
     * 深度优先搜索
     * @param grid
     * @param row
     * @param col
     */
    void dfs(vector<vector<char>> &grid, int row, int col) {
        // 修改为0
        grid[row][col] = '0';
        // 上
        if (row - 1 >= 0 && grid[row - 1][col] == '1') {
            dfs(grid, row - 1, col);
        }
        // 下
        if (row + 1 < grid.size() && grid[row + 1][col] == '1') {
            dfs(grid, row + 1, col);
        }
        // 左
        if (col - 1 >= 0 && grid[row][col - 1] == '1') {
            dfs(grid, row, col - 1);
        }
        // 右
        if (col + 1 < grid[0].size() && grid[row][col + 1] == '1') {
            dfs(grid, row, col + 1);
        }
    }

    /**
     * 广度优先搜索
     * @param grid
     * @param row
     * @param col
     */
    void bfs(vector<vector<char>> &grid, int row, int col) {
        grid[row][col] = '0';
        std::queue<std::pair<int, int>> _queue;
        _queue.push({row, col});
        while (!_queue.empty()) {
            auto ele = _queue.front();
            _queue.pop();
            auto i = ele.first;
            auto j = ele.second;
            if (i - 1 >= 0 && grid[i - 1][j] == '1') {
                grid[i - 1][j] = '0';
                _queue.push({i - 1, j});
            }
            if (i + 1 < grid.size() && grid[i + 1][j] == '1') {
                grid[i + 1][j] = '0';
                _queue.push({i + 1, j});
            }
            if (j - 1 >= 0 && grid[i][j - 1] == '1') {
                grid[i][j - 1] = '0';
                _queue.push({i, j - 1});
            }
            if (j + 1 < grid[0].size() && grid[i][j + 1] == '1') {
                grid[i][j + 1] = '0';
                _queue.push({i, j + 1});
            }
        }
    }
};

int main() {
    std::vector<std::vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'0', '1', '0', '1', '1'},
            {'0', '0', '0', '1', '1'},
            {'0', '0', '0', '0', '0'},
            {'0', '0', '1', '1', '1'}};
    std::cout << Solution().solve(grid) << std::endl;
}