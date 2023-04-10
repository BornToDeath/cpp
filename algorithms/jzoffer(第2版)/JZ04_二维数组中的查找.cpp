//
// Created by lixiaoqing on 2023/3/7.
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        const int rows = matrix.size(), cols = matrix[0].size();
        int i = 0, j = cols - 1;
        while (i < rows && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<int>> mat = {
            {1,  4,  7,  11, 15},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    std::cout << Solution().findNumberIn2DArray(mat, 10) << std::endl;
}