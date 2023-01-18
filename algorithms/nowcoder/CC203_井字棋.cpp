//
// Created by lixiaoqing on 2022/5/31.
//

#include <iostream>
#include <vector>

using namespace std;

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        int len = board.size();
        // 判断某行或某列
        for (int i = 0, j = 0; i < len && j < len; ++i, ++j) {
            if (isValid(board, i, j)) {
                return true;
            }
        }
        // 判断对角线
        for (int i = 0; i < len; ++i) {
            if (board[i][i] != 1) {
                break;
            }
            if (i == len - 1) {
                return true;
            }
        }
        for (int i = 0; i < len; ++i) {
            if (board[i][len - 1 - i] != 1) {
                break;
            }
            if (i == len - 1) {
                return true;
            }
        }
        return false;
    }

private:
    bool isValid(const vector<vector<int>> &mat, int row, int col) {
        int len = mat.size();
        // 判断行
        for (int i = 0; i < len; ++i) {
            if (mat[row][i] != 1) {
                return false;
            }
        }
        // 判断列
        for (int i = 0; i < len; ++i) {
            if (mat[i][col] != 1) {
                return false;
            }
        }
        return true;
    }
};