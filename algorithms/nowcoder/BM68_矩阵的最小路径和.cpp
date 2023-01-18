//
// Created by lixiaoqing on 2022/5/19.
//

#include <vector>

using namespace std;

class Solution {
public:
    /**
     *
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 1; i < rows; ++i) {
            matrix[i][0] += matrix[i - 1][0];
        }
        for (int i = 1; i < cols; ++i) {
            matrix[0][i] += matrix[0][i - 1];
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                matrix[i][j] += std::min(matrix[i][j - 1], matrix[i - 1][j]);
            }
        }
        return matrix[rows - 1][cols - 1];
    }
};