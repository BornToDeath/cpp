//
// Created by lixiaoqing on 2022/8/16.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        /**
         * 方法1：按行、按列、按九宫格分别遍历
         * 时间复杂度 O(n^2) ，空间复杂度 O(n)
         */
//        const int len = board.size();
//        std::unordered_set<char> set;
//        // 按行遍历
//        for (int i = 0; i < len; ++i) {
//            set.clear();
//            for (int j = 0; j < len; ++j) {
//                if (board[i][j] == '.') {
//                    continue;
//                }
//                if (set.count(board[i][j]) > 0) {
//                    return false;
//                }
//                set.insert(board[i][j]);
//            }
//        }
//        // 按列遍历
//        for (int i = 0; i < len; ++i) {
//            set.clear();
//            for (int j = 0; j < len; ++j) {
//                if (board[j][i] == '.') {
//                    continue;
//                }
//                if (set.count(board[j][i]) > 0) {
//                    return false;
//                }
//                set.insert(board[j][i]);
//            }
//        }
//        // 按九宫格遍历
//        for (int i = 0; i < len; i += 3) {
//            for (int j = 0; j < len; j += 3) {
//                set.clear();
//                for (int m = i; m < i + 3; ++m) {
//                    for (int n = j; n < j + 3; ++n) {
//                        if (board[m][n] == '.') {
//                            continue;
//                        }
//                        if (set.count(board[m][n]) > 0) {
//                            return false;
//                        }
//                        set.insert(board[m][n]);
//                    }
//                }
//            }
//        }
//        return true;

        /**
         * 方法2：一次遍历
         * 时间复杂度 O(n^2) ，空间复杂度 O(n^2)
         * 参考：https://leetcode.cn/problems/valid-sudoku/solution/you-xiao-de-shu-du-by-leetcode-solution-50m6/
         */
        const int len = board.size();
        // 9x9 行哈希表
        std::vector<std::vector<int>> rows(len, std::vector<int>(len, 0));
        // 9x9 列哈希表
        std::vector<std::vector<int>> cols(len, std::vector<int>(len, 0));
        // 3x3x9 九宫格哈希表
        std::vector<std::vector<std::vector<int>>> boxes(3, std::vector<std::vector<int>>(3, std::vector<int>(9, 0)));
        // 遍历
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                auto num = board[i][j] - '1';
                // rows[i][num]: 表示第 i 行的 num 元素是否已存在
                // cols[j][num]: 表示第 j 列的 num 元素是否已存在
                // boxes[i / 3][j / 3][num]: 表示第 [i / 3][j / 3] 个单元格的 num 元素是否存在
                if (rows[i][num] != 0 || cols[j][num] != 0 || boxes[i / 3][j / 3][num] != 0) {
                    return false;
                }
                rows[i][num] = cols[j][num] = boxes[i / 3][j / 3][num] = 1;
            }
        }
        return true;
    }
};

int main() {
    std::vector<std::vector<char>> board =
            {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    std::cout << Solution().isValidSudoku(board) << std::endl;
    return 0;
}