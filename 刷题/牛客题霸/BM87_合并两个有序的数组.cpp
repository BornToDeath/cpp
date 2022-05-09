//
// Created by lixiaoqing on 2022/5/9.
//

#include <iostream>

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        /**
         * 方法1：借助额外空间
         */
//        int *arr = new int[m + n]();
//        int pos = 0, i = 0, j = 0;
//        while (i < m && j < n) {
//            if (A[i] < B[j]) {
//                arr[pos++] = A[i++];
//            } else {
//                arr[pos++] = B[j++];
//            }
//        }
//        while (i < m) {
//            arr[pos++] = A[i++];
//        }
//        while (j < n) {
//            arr[pos++] = B[j++];
//        }
//        for (pos = 0; pos < m + n; ++pos) {
//            A[pos] = arr[pos];
//        }
//        delete[] arr;

        /**
         * 方法2：不借助额外空间
         */
        for (int i = 0; i < n; ++i) {
            auto j = m;
            while (j > 0 && B[i] < A[j - 1]) {
                A[j] = A[j - 1];
                --j;
            }
            A[j] = B[i];
            ++m;
        }
    }
};

int main() {
    int A[6] = {4, 5, 6, 0, 0, 0};
    int B[3] = {1, 2, 3};
    Solution().merge(A, 3, B, 3);
    for (int i = 0; i < 6; ++i) {
        std::cout << A[i] << ", ";
    }
    std::cout << std::endl;
}