//
// Created by lixiaoqing on 2023/7/27.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        /*
         * 方法1: 先确定行, 再二分查找
         * 时间复杂度 O(m + logn), 空间复杂度 O(1)
         */
        if (matrix.empty()) {
            return false;
        }
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i].back() >= target) {
                return std::binary_search(matrix[i].begin(), matrix[i].end(), target);
            }
        }
        return false;

        /*
         * 方法2: 两次二分查找, 第一次按行二分查找, 第二次按列二分查找
         * 时间复杂度 O(logmn), 空间复杂度 O(1)
         */
    }
};