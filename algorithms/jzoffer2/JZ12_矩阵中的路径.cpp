//
// Created by lixiaoqing on 2023/3/9.
//

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;


class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || word.empty()) {
            return false;
        }
        const int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0] && exist(board, word, rows, cols, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool exist(std::vector<std::vector<char>> &board, std::string &word,
               const int rows, const int cols, int x, int y, int pos) {
        if (x < 0 || x >= rows || y < 0 || y >= cols || pos >= word.length() || board[x][y] == '0' || board[x][y] != word[pos]) {
            return false;
        }
        if (pos == word.length() - 1) {
            return true;
        }
        auto c = board[x][y];
        board[x][y] = '0';
        if (exist(board, word, rows, cols, x + 1, y, pos + 1)) {
            return true;
        }
        if (exist(board, word, rows, cols, x - 1, y, pos + 1)) {
            return true;
        }
        if (exist(board, word, rows, cols, x, y + 1, pos + 1)) {
            return true;
        }
        if (exist(board, word, rows, cols, x, y - 1, pos + 1)) {
            return true;
        }
        board[x][y] = c;
        return false;
    }
};

int main() {
    std::vector<std::vector<char>> board = {{'a'}};
    std::string word = "a";
    std::cout << Solution().exist(board, word) << std::endl;
    return 0;
}