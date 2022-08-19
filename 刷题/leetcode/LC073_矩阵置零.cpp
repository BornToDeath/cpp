//
// Created by lixiaoqing on 2022/8/19.
//

#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        /**
         * 方法1：使用额外空间记录 0 出现的位置
         * 时间复杂度 O(mn) ，空间复杂度 O(m + n)
         */
//        if (matrix.empty()) {
//            return;
//        }
//        int rowSize = matrix.size(), colSize = matrix[0].size();
//        std::vector<int> rows(rowSize, 1), cols(colSize, 1);
//        for (int i = 0; i < rowSize; ++i) {
//            for (int j = 0; j < colSize; ++j) {
//                if (matrix[i][j] == 0) {
//                    rows[i] = cols[j] = 0;
//                }
//            }
//        }
//        for (int i = 0; i < rowSize; ++i) {
//            for (int j = 0; j < colSize; ++j) {
//                if (rows[i] == 0 || cols[j] == 0) {
//                    matrix[i][j] = 0;
//                }
//            }
//        }

        /**
         * 方法2：利用矩阵中第一行和第一列来记录矩阵中出现的 0 的位置
         * 时间复杂度 O(mn) ，空间复杂度 O(1)
         */
        if (matrix.empty()) {
            return;
        }
        int rows = matrix.size(), cols = matrix[0].size();
        // 记录第一行和第一列是否出现 0
        bool rowFlag = false, colFlag = false;
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                colFlag = true;
                break;
            }
        }
        for (int i = 0; i < cols; ++i) {
            if (matrix[0][i] == 0) {
                rowFlag = true;
                break;
            }
        }
        // 记录 0 出现的行和列
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        // 元素置 0
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 再处理第一行和第一列
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

void print(std::vector<std::vector<int>> &matrix) {
    for (auto &arr: matrix) {
        for (auto num: arr) {
            printf("%d, ", num);
        }
        printf("\n");
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}
    };
    Solution().setZeroes(matrix);
    print(matrix);
    return 0;
}