//
// Created by lixiaoqing on 2023/6/1.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        /*
         * 方法1: 分别记录 0 所在的行数和列数
         * 时间复杂度 O(m * n) , 空间复杂度 O(m + n)
         */
//        if (matrix.empty()) {
//            return;
//        }
//        const int M = matrix.size(), N = matrix.front().size();
//        std::vector<int> rowV(M), colV(N);
//        for (int i = 0; i < M; ++i) {
//            for (int j = 0; j < N; ++j) {
//                if (matrix[i][j] == 0) {
//                    rowV[i] = colV[j] = 1;
//                }
//            }
//        }
//        for (int i = 0; i < M; ++i) {
//            if (rowV[i] == 1) {
//                std::fill(matrix[i].begin(), matrix[i].end(), 0);
//            }
//        }
//        for (int i = 0; i < N; ++i) {
//            if (colV[i] == 1) {
//                for (int j = 0; j < M; ++j) {
//                    matrix[j][i] = 0;
//                }
//            }
//        }

        /*
         * 方法2: 原地操作
         * 时间复杂度 O(mn) , 空间复杂度 O(1)
         */
        if (matrix.empty()) {
            return;
        }
        const int M = matrix.size(), N = matrix.front().size();
        bool rowFlag = std::any_of(matrix[0].begin(), matrix[0].end(), [](int n) { return n == 0; });
        bool colFlag = false;
        for (int i = 0; i < M; ++i) {
            if (matrix[i][0] == 0) {
                colFlag = true;
                break;
            }
        }
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (rowFlag) {
            std::fill(matrix[0].begin(), matrix[0].end(), 0);
        }
        if (colFlag) {
            for (int i = 0; i < M; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
            {1, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 9, 5}
    };
    Solution().setZeroes(matrix);
    for (auto &arr: matrix) {
        for (auto n: arr) {
            std::cout << n << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}