//
// Created by lixiaoqing on 2022/11/25.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        /**
         * 方法1：维护一个元素个数为 k 个的大顶堆，遍历 matrix 直至结束，最终堆顶元素即为所求元素
         * 时间复杂度 O(n^2) ，空间复杂度 O(k)
         */
//        if (matrix.empty() || k <= 0) {
//            return -1;
//        }
//        std::priority_queue<int> _queue;
//        for (auto &v: matrix) {
//            for (auto e: v) {
//                if (k > 0) {
//                    _queue.push(e);
//                    --k;
//                } else {
//                    if (_queue.top() > e) {
//                        _queue.pop();
//                        _queue.push(e);
//                    }
//                }
//            }
//        }
//        return _queue.top();

        /**
         * 方法2：借助二分查找的思想
         * https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/solution/er-fen-chao-ji-jian-dan-by-jacksu1024/
         * 时间复杂度 O(nlog(maxValue - minValue)) ，空间复杂度 O(1)
         */
        if (matrix.empty() || k <= 0) {
            return -1;
        }

        int rows = matrix.size(), cols = matrix[0].size();

        // 在矩阵中查找元素值不大于 num 的元素个数
        auto countOfNotBigger = [&](int num) -> int {
            int count = 0;
            for (int i = rows - 1, j = 0; i >= 0 && j < cols;) {
                if (matrix[i][j] <= num) {
                    count += i + 1;
                    ++j;
                } else {
                    --i;
                }
            }
            return count;
        };

        int left = matrix[0][0], right = matrix[rows - 1][cols - 1];
        while (left < right) {
            // 注意：mid 必须如下这样算，不能这样子算: mid = (left + right) / 2 。例如，对于 left=-5, right=-4 ，两种方式计算的 mid 不一样
            auto mid = left + ((right - left) >> 1);
            int count = countOfNotBigger(mid);
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
            {-5, -4},
            {-5, -4}
//            {1,  5,  9},
//            {10, 11, 13},
//            {12, 13, 15}
    };
    std::cout << Solution().kthSmallest(matrix, 2) << std::endl;
}