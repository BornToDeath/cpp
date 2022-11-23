//
// Created by lixiaoqing on 2022/11/23.
//

#include <vector>
#include <iostream>

using namespace std;

void print(std::vector<std::vector<int>> &board) {
    for (auto &v: board) {
        for (auto e: v) {
            std::cout << e << ", ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        /**
         * 方法1：先复制一份 board, 然后计算
         * 时间复杂度 O(mn) ，空间复杂度 O(mn)
         */
//        if (board.empty()) {
//            return;
//        }
//        auto copy = board;
//        int rows = board.size(), cols = board[0].size();
//        // 计算活细胞的个数
//        auto liveCellCount = [&](int row, int col) -> int {
//            int aliveCellCount = 0;
//            for (int i = row - 1; i <= row + 1; ++i) {
//                for (int j = col - 1; j <= col + 1; ++j) {
//                    if (i < 0 || i >= rows || j < 0 || j >= cols || i == row && j == col) {
//                        continue;
//                    }
//                    if (copy[i][j] == 1) {
//                        ++aliveCellCount;
//                    }
//                }
//            }
//            return aliveCellCount;
//        };
//        // 遍历 board 每个细胞
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                auto count = liveCellCount(i, j);
//                if (copy[i][j] == 1) {
//                    board[i][j] = (count == 2 || count == 3) ? 1 : 0;
//                } else {
//                    board[i][j] = count == 3 ? 1 : 0;
//                }
//            }
//        }

        /**
         * 方法2：原地更新
         * 时间复杂度 O(mn) ，空间复杂度 O(1)
         */
        if (board.empty()) {
            return;
        }
        int rows = board.size(), cols = board[0].size();
        auto liveCellCount = [&](int row, int col) -> int {
            int aliveCellCount = 0;
            for (int i = row - 1; i <= row + 1; ++i) {
                for (int j = col - 1; j <= col + 1; ++j) {
                    if (i < 0 || i >= rows || j < 0 || j >= cols || i == row && j == col) {
                        continue;
                    }
                    if (board[i][j] == 1 || board[i][j] == -1) {
                        ++aliveCellCount;
                    }
                }
            }
            return aliveCellCount;
        };
        // 遍历 board 每个细胞
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                auto count = liveCellCount(i, j);
                if (board[i][j] == 1) {
                    // -1 代表这个细胞过去是活的现在是死的
                    board[i][j] = (count == 2 || count == 3) ? 1 : -1;
                } else {
                    // 2 代表这个细胞过去是死的现在是活的
                    board[i][j] = (count == 3) ? 2 : 0;
                }
            }
        }
        // 再次更新
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                board[i][j] = (board[i][j] > 0) ? 1 : 0;
            }
        }
    }
};

int main() {
    std::vector<std::vector<int>> board = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 0}
    };
    Solution().gameOfLife(board);
    print(board);
    return 0;
}