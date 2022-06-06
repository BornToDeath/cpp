//
// Created by lixiaoqing on 2022/6/6.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for (auto &arr: matrix) {
            std::reverse(arr.begin(), arr.end());
        }
        int len = matrix.size();
        for (int i = 0, j = len - 1; i < len && j >= 0; ++i, --j) {
            for (int k = i; k < len; ++k) {
                swap(matrix[i][len - k - 1], matrix[k][j]);
            }
        }
    }
};