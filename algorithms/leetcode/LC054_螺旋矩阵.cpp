//
// Created by lixiaoqing on 2022/8/18.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return {};
        }
        std::vector<int> ans;
        int rows = matrix.size(), cols = matrix[0].size();
        int x1 = 0, y1 = 0, x2 = rows - 1, y2 = cols - 1;
        while (x1 <= x2 && y1 <= y2) {
            for (int i = y1; i <= y2; ++i) {
                ans.push_back(matrix[x1][i]);
            }
            ++x1;
            for (int i = x1; i <= x2; ++i) {
                ans.push_back(matrix[i][y2]);
            }
            --y2;
            if (x1 <= x2) {
                for (int i = y2; i >= y1; --i) {
                    ans.push_back(matrix[x2][i]);
                }
                --x2;
            }
            if (y1 <= y2) {
                for (int i = x2; i >= x1; --i) {
                    ans.push_back(matrix[i][y1]);
                }
                ++y1;
            }
        }
        return ans;
    }
};