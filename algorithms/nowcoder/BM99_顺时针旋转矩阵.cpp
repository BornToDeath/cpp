//
// Created by lixiaoqing on 2022/5/27.
//

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<std::vector<int>> &matrix) {
    for (const auto &arr: matrix) {
        for (auto num:arr) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        /**
         * 方法1：借助额外空间。时间复杂度O(n^2)，空间复杂度O(n^2)
         */
//        if (mat.empty()) {
//            return {};
//        }
//        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                res[j][n - i - 1] = mat[i][j];
//            }
//        }
//        return res;

        /**
         * 方法2：时间复杂度O(n^2)，空间复杂度O(1)
         */
        if (mat.empty()) {
            return {};
        }
        for (auto &arr:mat) {
            std::reverse(arr.begin(), arr.end());
        }
        for (int i = 0; i < n; ++i) {
            for (int j = n - i - 1; j >= 0; --j) {
                std::swap(mat[i][j], mat[n - j - 1][n - i - 1]);
            }
        }
        return mat;
    }
};

int main() {
    std::vector<std::vector<int>> mat = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    print(mat);
    auto res = Solution().rotateMatrix(mat, mat.size());
    print(res);
    return 0;
}