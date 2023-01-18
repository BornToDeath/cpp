//
// Created by lixiaoqing on 2022/7/15.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        for (int i = 0, j = matrix[0].size() - 1; i < matrix.size() && j >= 0;) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
}

};