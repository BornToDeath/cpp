//
// Created by lixiaoqing on 2023/3/15.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return {};
        }
        std::vector<int> ans;
        for (int x1 = 0, y1 = 0, x2 = matrix.size() - 1, y2 = matrix[0].size() - 1; x1 <= x2 && y1 <= y2;) {
            for (int i = y1; i <= y2; ++i) {
                ans.emplace_back(matrix[x1][i]);
            }
            ++x1;
            for (int i = x1; i <= x2; ++i) {
                ans.emplace_back(matrix[i][y2]);
            }
            --y2;
            if (x1 <= x2) {
                for (int i = y2; i >= y1; --i) {
                    ans.emplace_back(matrix[x2][i]);
                }
                --x2;
            }
            if (y1 <= y2) {
                for (int i = x2; i >= x1; --i) {
                    ans.emplace_back(matrix[i][y1]);
                }
                ++y1;
            }
        }
        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16}
    };
//    matrix = {
//            {1, 2,  3},
//            {5, 6,  7},
//            {9, 10, 11}
//    };
    matrix = {{1, 2, 3, 4}};
    auto ans = Solution().spiralOrder(matrix);
    for (auto num: ans) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}