//
// Created by lixiaoqing on 2022/6/14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        if (mat.empty()) {
            return {};
        }
        int rows = mat.size();
        int cols = mat[0].size();
        std::vector<int> res(rows * cols, 0);
        for (int i = 0, j = 0, k = 0; k < res.size(); ++k) {
            printf("i=%d, j=%d\n", i, j);
            res[k] = mat[i][j];
            // 偶数向上遍历，奇数向下遍历
            if ((i + j) % 2 == 0) {
                if (j == cols - 1) {
                    ++i;
                } else if (i == 0) {
                    ++j;
                } else {
                    --i;
                    ++j;
                }
            } else {
                if (i == rows - 1) {
                    ++j;
                } else if (j == 0) {
                    ++i;
                } else {
                    ++i;
                    --j;
                }
            }
        }
        return res;
    }
};

int main() {
//    std::vector<std::vector<int>> mat = {
//            {1, 2, 3, 10},
//            {4, 5, 6, 11},
//            {7, 8, 9, 12}
//    };
    std::vector<std::vector<int>> mat = {
            {1, 2},
            {4, 5}
    };
    auto res = Solution().findDiagonalOrder(mat);
    for (auto num: res) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}