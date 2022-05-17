//
// Created by lixiaoqing on 2022/5/17.
//

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int solve(vector<vector<int> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int max = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                max = std::max(max, dfs(matrix, i, j));
            }
        }
        return max;
    }

private:
    int dfs(vector<vector<int>> &matrix, int row, int col) {
        // 如果为 -1 说明已经走过此节点了
        if (matrix[row][col] == -1) {
            return -1;
        }
        int res = 1;
        // 上
        if (row - 1 >= 0 && matrix[row - 1][col] > matrix[row][col]) {
            res = std::max(res, 1 + dfs(matrix, row - 1, col));
        }
        // 下
        if (row + 1 < matrix.size() && matrix[row + 1][col] > matrix[row][col]) {
            res = std::max(res, 1 + dfs(matrix, row + 1, col));
        }
        // 左
        if (col - 1 >= 0 && matrix[row][col - 1] > matrix[row][col]) {
            res = std::max(res, 1 + dfs(matrix, row, col - 1));
        }
        // 右
        if (col + 1 < matrix[0].size() && matrix[row][col + 1] > matrix[row][col]) {
            res = std::max(res, 1 + dfs(matrix, row, col + 1));
        }
        return res;
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
            {4, 3, 3, 6, 6, 3, 2, 1, 0, 7},
            {1, 8, 2, 8, 5, 9, 2, 8, 3, 1},
            {8, 0, 9, 2, 4, 3, 2, 4, 3, 7},
            {1, 2, 2, 6, 3, 0, 3, 9, 7, 0},
            {7, 4, 3, 8, 8, 3, 2, 4, 6, 8},
            {2, 8, 9, 2, 9, 3, 0, 8, 7, 8},
            {8, 9, 9, 4, 6, 3, 3, 4, 9, 6},
            {2, 8, 3, 8, 1, 3, 7, 3, 0, 7},
            {2, 1, 1, 6, 4, 1, 0, 8, 1, 6},
            {4, 1, 3, 6, 3, 4, 4, 4, 0, 3}
    };
    printf("%d\n", Solution().solve(matrix));
    return 0;
}