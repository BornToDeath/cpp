//
// Created by lixiaoqing on 2022/8/25.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        /**
         * 思想：因为值为 'O' 的边界元素是不能被修改的，所以 DFS 处理边界为 'O' 的元素的联通元素
         * 参考：https://leetcode.cn/problems/surrounded-regions/solution/bei-wei-rao-de-qu-yu-by-leetcode-solution/
         * 时间复杂度 O(mn) ，空间复杂度 O(mn)
         */
        if (board.empty()) {
            return;
        }
        int m = board.size(), n = board[0].size();
        // dp[i][j] = 1 表示该元素不能被修改
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        // 处理边界元素
        for (int i = 0; i < n; ++i) {
            dfs(board, 0, i, dp);
            dfs(board, m - 1, i, dp);
        }
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0, dp);
            dfs(board, i, n - 1, dp);
        }
        // 遍历 board
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (board[i][j] == 'O' && dp[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }

private:
    void dfs(std::vector<std::vector<char>> &board, int x, int y, std::vector<std::vector<int>> &dp) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
            return;
        }
        if (board[x][y] == 'X' || dp[x][y]) {
            return;
        }
        dp[x][y] = 1;
        dfs(board, x - 1, y, dp);
        dfs(board, x + 1, y, dp);
        dfs(board, x, y - 1, dp);
        dfs(board, x, y + 1, dp);
    }
};

template<typename T>
void print(std::vector<std::vector<T>> &mat) {
    for (auto &arr: mat) {
        for (auto &e: arr) {
            std::cout << e << ", ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<char>> board = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
    };
//    print(board);
    Solution().solve(board);
    print(board);
    return 0;
}