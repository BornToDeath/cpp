//
// Created by lixiaoqing on 2023/6/1.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        const int N = matrix.size();
        // 1. 以行为轴将列对称翻转
        for (int i = 0; i < N / 2; ++i) {
            for (int j = 0; j < N; ++j) {
                std::swap(matrix[i][j], matrix[N - 1 - i][j]);
            }
        }
        // 2. 以左上右下的对角线为轴进行对称翻转
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
            {5,  1,  9,  11},
            {2,  4,  8,  10},
            {13, 3,  6,  7},
            {15, 14, 12, 16}
    };
    Solution().rotate(matrix);
    for (auto &arr: matrix) {
        for (auto n: arr) {
            std::cout << n << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}