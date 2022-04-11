//
// Created by lixiaoqing on 2021/12/10.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void printArray(const vector<int> &arr) {
    std::for_each(arr.begin(), arr.end(), [](int elem) { std::cout << elem << ", "; });
    std::cout << std::endl;
}

class Solution {
public:
    vector<int> multiply(const vector<int> &A) {
        /**
         * 方法1：使用除法运算，但不满足题目要求
         */
//        const int product = std::accumulate(A.begin(), A.end(), 1, [](int base, int num) {
//            return (num == 0) ? base : (base * num);
//        });
//        vector<int> res(A.size(), 0);
//        for (int i = 0; i < A.size(); ++i) {
//            if (A[i] != 0) {
//                res[i] = product / A[i];
//            }
//        }
//        return res;

        /**
         * 方法2：不使用除法运算，时间复杂度 O(n^2)
         */
//        if (A.empty()) {
//            return {};
//        }
//        std::vector<int> res(A.size(), 0);
//        for (int i = 0; i < A.size(); ++i) {
//            auto num = 1;
//            for (int j = 0; j < A.size(); ++j) {
//                if (i == j) {
//                    continue;
//                }
//                num *= A[j];
//            }
//            res[i] = num;
//        }
//        return res;

        /**
         * 方法3：动态规划，不使用除法运算，时间复杂度 O(n)
         * dp[i] = A[0] * A[1] * ... * A[i-1] * A[i+1] * ... * A[n]
         *       = left[i] * right[i]
         * 其中，left[i] = left[i-1] * A[i-1],
         *      right[i] = right[i+1] * A[i+1]
         */
        if (A.empty()) {
            return {};
        }
        std::vector<int> dp(A.size(), 0);
        dp[0] = 1;
        // 计算左半部分乘积
        for (int i = 1; i < A.size(); ++i) {
            dp[i] = dp[i - 1] * A[i - 1];
        }
        // 计算右半部分乘积
        auto temp = 1;
        for (int i = A.size() - 2; i >= 0; --i) {
            temp *= A[i + 1];  // 存储右半部分乘积
            dp[i] *= temp;  // 计算左右两个部分乘积
        }
        return dp;
    }
};

int main() {
    vector<int> nums = {10, 2, 5, 2};
    printArray(nums);

    Solution solution;
    auto ret = solution.multiply(nums);
    printArray(ret);

    return 0;
}