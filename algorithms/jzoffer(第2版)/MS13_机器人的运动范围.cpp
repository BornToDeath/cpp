//
// Created by lixiaoqing on 2023/4/6.
//

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int movingCount(int m, int n, int k) {
        /*
         * 方法1: BFS
         * 时间复杂度 O(mn) , 空间复杂度 O(mn)
         */
//        if (m == 0 || n == 0) {
//            return 0;
//        }
//        if (k == 0) {
//            return 1;
//        }
//        // 数位和
//        auto digitSum = [](int num) {
//            int sum = 0;
//            while (num) {
//                sum += num % 10;
//                num /= 10;
//            }
//            return sum;
//        };
//        std::vector<std::vector<int>> arr(m, std::vector<int>(n, 0));
//        int count = 0;
//        std::queue<std::pair<int, int>> q;
//        q.push({0, 0});
//        while (!q.empty()) {
//            auto ele = q.front();
//            q.pop();
//            if (arr[ele.first][ele.second] == 1) {
//                continue;
//            }
//            arr[ele.first][ele.second] = 1;
//            ++count;
//            // 向右
//            if (ele.second + 1 < n && (digitSum(ele.first) + digitSum(ele.second + 1)) <= k) {
//                q.push({ele.first, ele.second + 1});
//            }
//            // 向下
//            if (ele.first + 1 < m && (digitSum(ele.first + 1) + digitSum(ele.second)) <= k) {
//                q.push({ele.first + 1, ele.second});
//            }
//        }
//        return count;

        /*
         * 方法2: 动态规划
         * 时间复杂度 O(mn) , 空间复杂度 O(mn)
         */
        if (m == 0 || n == 0 || k < 0) {
            return 0;
        }
        // 数位和
        auto digitSum = [](int num) {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };
        int count = 0;
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (digitSum(i) + digitSum(j) > k) {
                    continue;
                }
                if (i == 0 || j == 0) {
                    if (i == 0 && j == 0) {
                        dp[i][j] = 1;
                    } else if (i == 0) {
                        dp[i][j] = dp[i][j - 1];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                } else {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};

int main() {
    std::cout << Solution().movingCount(2, 3, 1) << std::endl;
    std::cout << Solution().movingCount(3, 1, 0) << std::endl;
    return 0;
}