//
// Created by lixiaoqing on 2022/6/6.
//

#include <iostream>

class Solution {
public:
    /**
     *
     * @param A int整型一维数组
     * @param n int A数组长度
     * @return int整型
     */
    int maxSubArray(int *A, int n) {
        /**
         * 方法1：
         */
//        int max = A[0];
//        int sum = A[0];
//        for (int i = 1; i < n; ++i) {
//            if (sum < 0 || sum + A[i] < 0) {
//                sum = A[i];
//            } else {
//                sum += A[i];
//            }
//            max = std::max(max, sum);
//        }
//        return max;

        /**
         * 方法2：
         */
        int sum = 0, max = A[0];
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            max = std::max(sum, max);
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};

int main() {
    int A[] = {-2, 0, -3, 4, -2, 2, 2, -5, 4};
    std::cout << Solution().maxSubArray(A, sizeof(A) / sizeof(int)) << std::endl;
    return 0;
}