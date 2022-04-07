//
// Created by lixiaoqing on 2022/4/7.
//

#include <iostream>
#include <vector>

using namespace std;

void printArray(const std::vector<int> &array) {
    if (array.empty()) {
        return;
    }
    std::for_each(array.begin(), array.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
}

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.empty()) {
            return {};
        }

        std::vector<int> res;
        int row1 = 0;
        int col1 = 0;
        int row2 = matrix.size() - 1;
        int col2 = matrix[0].size() - 1;
        while (row1 <= row2 && col1 <= col2) {
            for (int i = col1; i <= col2; ++i) {
                res.emplace_back(matrix[row1][i]);
            }
            ++row1;

            for (int i = row1; i <= row2; ++i) {
                res.emplace_back(matrix[i][col2]);
            }
            --col2;

            if (row1 <= row2) {
                for (int i = col2; i >= col1; --i) {
                    res.emplace_back(matrix[row2][i]);
                }
                --row2;
            }

            if (col1 <= col2) {
                for (int i = row2; i >= row1; --i) {
                    res.emplace_back(matrix[i][col1]);
                }
                ++col1;
            }
        }
        return res;
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16}};
    matrix = {{1}};
    matrix = {{1, 2},
              {3, 4}};
    matrix = {{1, 2, 3, 4, 5}};
    matrix = {{1},
              {2},
              {3},
              {4},
              {5}};
    auto res = Solution().printMatrix(matrix);
    printArray(res);
    return 0;
}