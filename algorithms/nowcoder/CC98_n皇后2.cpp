//
// Created by lixiaoqing on 2022/6/6.
//

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     *
     * @param n int整型
     * @return int整型
     */
    int totalNQueens(int n) {
        std::vector<int> dp(n, 0);
        nQueens(dp, 0);
        return count;
    }

private:
    void nQueens(std::vector<int> &dp, int row) {
        int len = dp.size();
        if (row == len) {
            ++count;
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (isValid(dp, row, i)) {
                dp[row] = i;
                nQueens(dp, row + 1);
            }
        }
    }

    bool isValid(std::vector<int> &dp, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (i == row || dp[i] == col || std::abs(i - row) == std::abs(dp[i] - col)) {
//                printf("i=%d, dp[i]=%d, row=%d, col=%d\n", i, dp[i], row, col);
                return false;
            }
        }
        return true;
    }

private:
    int count = 0;
};

int main() {
    std::cout << Solution().totalNQueens(4) << std::endl;
    return 0;
}