//
// Created by lixiaoqing on 2022/7/12.
//

#include <vector>

using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>> &indices) {
        /**
         * 方法1：直接模拟一个数组
         */
//        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
//        for (auto &pair: indices) {
//            set(dp, pair[0], pair[1]);
//        }
//        int count = 0;
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if ((dp[i][j] & 0x1) == 1) {
//                    ++count;
//                }
//            }
//        }
//        return count;

        /**
         * 方法2：在方法1的基础上进行优化
         */
        std::vector<int> rows(m);
        std::vector<int> cols(n);
        for (auto &pair: indices) {
            ++rows[pair[0]];
            ++cols[pair[1]];
        }
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                count += (rows[i] + cols[j]) & 0x1;
            }
        }
        return count;

        /**
         * 方法3：在方法2的基础上进行优化（归纳为数学公式）
         * 见：https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix/solution/qi-shu-zhi-dan-yuan-ge-de-shu-mu-by-leet-oa4o/
         */
//        std::vector<int> rows(m);
//        std::vector<int> cols(n);
//        for (auto &pair: indices) {
//            ++rows[pair[0]];
//            ++cols[pair[1]];
//        }
//        int oddx = std::count_if(rows.begin(), rows.end(), [](int num) { return (num & 0x1) == 1; });  // 行中奇数个数
//        int oddy = std::count_if(cols.begin(), cols.end(), [](int num) { return (num & 0x1) == 1; });  // 列中奇数个数
//        return oddx * (n - oddy) + oddy * (m - oddx);
    }

private:
    void set(vector<vector<int>> &dp, int row, int col) {
        for (int i = 0; i < dp[0].size(); ++i) {
            ++dp[row][i];
        }
        for (int i = 0; i < dp.size(); ++i) {
            ++dp[i][col];
        }
    }
};