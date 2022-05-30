//
// Created by lixiaoqing on 2022/5/9.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        /**
         * 方法1：递归
         */
//        if (matrix.empty()) {
//            return {};
//        }
//        spiralOrder(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
//        return res;

        /**
         * 方法2：迭代
         */
        if (matrix.empty()) {
            return {};
        }
        std::vector<int> nums;
        int x1 = 0, y1 = 0;
        int x2 = matrix.size() - 1, y2 = matrix[0].size() - 1;
        while (x1 <= x2 && y1 <= y2) {
            for (int i = y1; i <= y2; ++i) {
                nums.emplace_back(matrix[x1][i]);
            }
            ++x1;
            for (int i = x1; i <= x2; ++i) {
                nums.emplace_back(matrix[i][y2]);
            }
            --y2;
            if (x1 <= x2) {
                for (int i = y2; i >= y1; --i) {
                    nums.emplace_back(matrix[x2][i]);
                }
                --x2;
            }
            if (y1 <= y2) {
                for (int i = x2; i >= x1; --i) {
                    nums.emplace_back(matrix[i][y1]);
                }
                ++y1;
            }
        }
        return nums;
    }

private:
    void spiralOrder(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) {
            return;
        }
        for (int i = y1; i <= y2; ++i) {
            res.emplace_back(matrix[x1][i]);
        }
        ++x1;
        for (int i = x1; i <= x2; ++i) {
            res.emplace_back(matrix[i][y2]);
        }
        --y2;
        if (x1 <= x2) {
            for (int i = y2; i >= y1; --i) {
                res.emplace_back(matrix[x2][i]);
            }
            --x2;
        }
        if (y1 <= y2) {
            for (int i = x2; i >= x1; --i) {
                res.emplace_back(matrix[i][y1]);
            }
            ++y1;
        }
        spiralOrder(matrix, x1, y1, x2, y2);
    }

private:
    std::vector<int> res;
};