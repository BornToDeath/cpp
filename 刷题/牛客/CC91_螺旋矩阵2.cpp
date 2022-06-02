//
// Created by lixiaoqing on 2022/6/2.
//

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<std::vector<int>> &mat) {
    for (const auto &arr: mat) {
        for (auto num: arr) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    /**
     *
     * @param n int整型
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > generateMatrix(int n) {
        /**
         * 方法1：
         */
//        std::vector<std::vector<int>> mat(n, std::vector<int>(n, 0));
//        int num = 0;
//        for (int i = 0, j = n - 1; i <= j; ++i, --j) {
//            // 上
//            for (int k = i; k <= j; ++k) {
//                mat[i][k] = ++num;
//            }
//            // 右
//            for (int k = i + 1; k <= j; ++k) {
//                mat[k][j] = ++num;
//            }
//            // 下
//            for (int k = j - 1; k >= i; --k) {
//                mat[j][k] = ++num;
//            }
//            // 左
//            for (int k = j - 1; k > i; --k) {
//                mat[k][i] = ++num;
//            }
////            print(mat);
//        }
//        return mat;

        /**
         * 方法2：
         */
        std::vector<std::vector<int>> mat(n, std::vector<int>(n, 0));
        int num = 0;
        for (int row = 0, col = n - 1; row <= col; ++row, --col) {
            if (row == col) {
                mat[row][col] = ++num;
                continue;
            }
            int i = row, j = row;
            while (j < col) {
                mat[i][j++] = ++num;
            }
            while (i < col) {
                mat[i++][j] = ++num;
            }
            while (j > row) {
                mat[i][j--] = ++num;
            }
            while (i > row) {
                mat[i--][j] = ++num;
            }
        }
        return mat;
    }
};

int main() {
    auto mat = Solution().generateMatrix(1);
    print(mat);
    return 0;
}