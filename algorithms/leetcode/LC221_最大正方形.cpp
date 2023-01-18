//
// Created by lixiaoqing on 2022/7/14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        /**
         * 方法1：动态规划
         * dp[i][j] 表示以 <i, j> 为右下角的最大正方形的边长，那么：
         * dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1, if matrix[i][j] = '1'
         *          = 0,                                             else
         *
         */
        if (matrix.empty()) {
            return 0;
        }
        int max = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = matrix[i][j] - '0';
                    } else {
                        dp[i][j] = std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    }
                    max = std::max(max, dp[i][j]);
                }
            }
        }
        return max * max;

        /**
         * 方法2：分别计算以每个元素为左上顶点的最大正方形。不AC，时间超限
         */
//        if (matrix.empty()) {
//            return 0;
//        }
//        int max = 0;
//        int rows = matrix.size(), cols = matrix[0].size();
//        for (int i = 0; i < rows; ++i) {
//            for (int j = 0; j < cols; ++j) {
//                if (matrix[i][j] == '0') {
//                    continue;
//                }
//                // 计算可能的最大正方形边长
//                int step = 0;
//                for (; i + step < rows && j + step < cols; ++step) {
//                    // 判断新增的一行一列是否均为 '1'
//                    bool flag = true;
//                    for (int k = 0; k <= step; ++k) {
//                        if (matrix[i + step][j + k] == '0' || matrix[i + k][j + step] == '0') {
//                            flag = false;
//                            break;
//                        }
//                    }
//                    if (flag) {
//                        max = std::max(max, step + 1);
//                    } else {
//                        break;
//                    }
//                }
//            }
//        }
//        return max * max;
    }
};

int main() {
    std::vector<std::vector<char>> matrix = {
            {'1', '0', '1', '1', '0', '1'},
            {'1', '1', '1', '1', '1', '1'},
            {'0', '1', '1', '0', '1', '1'},
            {'1', '1', '1', '0', '1', '0'},
            {'0', '1', '1', '1', '1', '1'},
            {'1', '1', '0', '1', '1', '1'}
    };
    std::cout << Solution().maximalSquare(matrix) << std::endl;
    return 0;
}