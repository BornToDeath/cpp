//
// Created by lixiaoqing on 2022/4/6.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param matrix char字符型vector<vector<>>
     * @param word string字符串
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> > &matrix, string word) {
        if (matrix.empty()) {
            return false;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        visited = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == word.at(0)) {
                    // 第一个字母正确的时候，进入dfs
                    dfs(matrix, word, 0, i, j);
                    if (flag) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    void dfs(const std::vector<std::vector<char>> &matrix, const std::string &word, int loc, int x, int y) {
        // 如果已经找到了，返回
        if (flag) {
            return;
        }
        // 如果超出矩阵范围，返回
        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()) {
            return;
        }
        // 如果不是要找的字母，返回
        if (matrix[x][y] != word[loc]) {
            return;
        }
        // 如果已经访问过，返回
        if (visited[x][y]) {
            return;
        }
        // 找到了
        if (loc == word.length() - 1) {
            flag = true;
            return;
        }
        visited[x][y] = true;
        dfs(matrix, word, loc + 1, x - 1, y);
        dfs(matrix, word, loc + 1, x + 1, y);
        dfs(matrix, word, loc + 1, x, y - 1);
        dfs(matrix, word, loc + 1, x, y + 1);
        visited[x][y] = false;  // 回溯
    }

private:
    std::vector<std::vector<bool>> visited;
    bool flag = false;
};