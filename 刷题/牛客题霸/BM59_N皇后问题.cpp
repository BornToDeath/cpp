//
// Created by lixiaoqing on 2022/5/30.
//

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     *
     * @param n int整型 the n
     * @return int整型
     */
    int Nqueen(int n) {
        if (n <= 0) {
            return 0;
        }
        // i 表示行号，dp[i] 表示列号
        std::vector<int> dp(n, 0);
        recursion(dp, 0);
        return count;
    }

private:
    void recursion(std::vector<int> &dp, int row) {
        const int len = dp.size();
        if (row == len) {
            ++count;
//            printf("count=%d\n", count);
            return;
        }
        // 遍历列
        for (int i = 0; i < len; ++i) {
//            printf("row=%d, i=%d, isValid=%d\n", row, i, isValid(dp, row, i));
            if (isValid(dp, row, i)) {
                dp[row] = i;
                recursion(dp, row + 1);
            }
        }
    }

    bool isValid(const std::vector<int> &array, int row, int col) {
        // 遍历行
        for (int i = 0; i < row; ++i) {
            //不能同行同列同一斜线
            if (row == i || col == array[i] || abs(row - i) == abs(col - array[i])) {
                return false;
            }
        }
        return true;
    }

private:
    int count = 0;
};

int main() {
    std::cout << Solution().Nqueen(3) << std::endl;
    return 0;
}
