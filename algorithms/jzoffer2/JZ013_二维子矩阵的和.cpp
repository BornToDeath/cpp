//
// Created by lixiaoqing on 2023/5/29.
//

#include <iostream>
#include <vector>

using std::vector;

/*
 * 方法: 二维前缀和
 */
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) : mat(matrix) {
        for (int i = 0; i < mat.size(); ++i) {
            int n = 0;
            for (int j = 0; j < mat.front().size(); ++j) {
                n += mat[i][j];
                mat[i][j] = n + (i > 0 ? mat[i - 1][j] : 0);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = mat[row2][col2];
        if (row1 - 1 >= 0) {
            ans -= mat[row1 - 1][col2];
        }
        if (col1 - 1 >= 0) {
            ans -= mat[row2][col1 - 1];
        }
        if (row1 - 1 >= 0 && col1 - 1 >= 0) {
            ans += mat[row1 - 1][col1 - 1];
        }
        return ans;
    }

private:
    std::vector<std::vector<int>> mat;
};

int main() {
    std::vector<std::vector<int>> matrix = {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
    };
    NumMatrix m1(matrix);
    std::cout << m1.sumRegion(2, 1, 4, 3) << std::endl;
    std::cout << m1.sumRegion(1, 1, 2, 2) << std::endl;
    std::cout << m1.sumRegion(1, 2, 2, 4) << std::endl;
    return 0;
}