//
// Created by lixiaoqing on 2022/6/1.
//

#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        /**
         * 方法：题目要求空间复杂度O(1)，可使用此方法：利用矩阵第一行和第一列的空间。
         * 此方法的时间复杂度为O(mn)，空间复杂度O(1)。
         */
        if (matrix.empty()) {
            return;
        }
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        // 遍历第一行和第一列，记录是否有0
        bool rowFlag = false, colFlag = false;
        for (int i = 0; i < cols; ++i) {
            if (matrix[0][i] == 0) {
                rowFlag = true;
                break;
            }
        }
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                colFlag = true;
                break;
            }
        }
        // 利用第一行记录矩阵中0所在的行数和列数
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        // 对0所在的行和列赋0
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 处理第一行和第一列
        if (rowFlag) {
            for (int i = 0; i < cols; ++i) {
                matrix[0][i] = 0;
            }
        }
        if (colFlag) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};