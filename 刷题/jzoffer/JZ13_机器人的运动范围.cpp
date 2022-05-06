//
// Created by lixiaoqing on 2022/5/6.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        dp[0][0] = 1;
        for (auto i = 0; i < rows; ++i) {
            for (auto j = 0; j < cols; ++j) {
                if (sumOfAllNumbers(i) + sumOfAllNumbers(j) > threshold) {
                    continue;
                }
                if (i == 0 || j == 0) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    if (i == 0) {
                        dp[i][j] = dp[i][j - 1];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                } else {
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
                }
            }
        }
        int count = 0;
        for (auto &v: dp) {
            for (auto num: v) {
                if (num == 1) {
                    ++count;
                }
            }
        }
        return count;
    }

private:
    static int sumOfAllNumbers(int number) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
};

int main() {
    std::cout << Solution().movingCount(1, 2, 3) << std::endl;
    return 0;
}

