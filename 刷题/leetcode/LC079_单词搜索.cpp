//
// Created by lixiaoqing on 2022/6/27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty()) {
            return false;
        }
        if (word.empty()) {
            return true;
        }
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0]) {
                    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
                    if (check(board, visited, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool check(std::vector<std::vector<char>> &board, std::vector<std::vector<bool>> &visited,
               int i, int j, std::string &word, int pos) {
        if (pos == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[pos] || visited[i][j]) {
            return false;
        }
        visited[i][j] = true;
        bool ret = check(board, visited, i - 1, j, word, pos + 1) || check(board, visited, i + 1, j, word, pos + 1) ||
                   check(board, visited, i, j - 1, word, pos + 1) || check(board, visited, i, j + 1, word, pos + 1);
        visited[i][j] = false;
        return ret;
    }
};

int main() {
    std::vector<std::vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'E', 'S'},
            {'A', 'D', 'E', 'E'},
    };
    std::string word = "ABCESEEEFS";
    std::cout << Solution().exist(board, word) << std::endl;
    return 0;
}