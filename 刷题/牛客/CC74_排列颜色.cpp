//
// Created by lixiaoqing on 2022/6/1.
//

#include <iostream>

void print(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    void sortColors(int A[], int n) {
        /**
         * 方法1：计数排序的思想
         */
//        int countOne = 0;
//        int countTwo = 0;
//        for (int i = 0; i < n; ++i) {
//            if (A[i] == 1) {
//                ++countOne;
//            } else if (A[i] == 2) {
//                ++countTwo;
//            }
//        }
//        for (int i = 0; i < n; ++i) {
//            if (i < n - countOne - countTwo) {
//                A[i] = 0;
//            } else if (i < n - countTwo) {
//                A[i] = 1;
//            } else {
//                A[i] = 2;
//            }
//        }

        /**
         * 方法2（推荐）：三路快排
         */
        int start = 0, end = n - 1;
        for (int i = 0; i <= end;) {
            if (A[i] == 1) {
                ++i;
            } else if (A[i] == 0) {
                std::swap(A[i++], A[start++]);
            } else if (A[i] == 2) {
                std::swap(A[i], A[end--]);
            }
        }
    }
};

int main() {
    int A[] = {1, 2, 0, 2, 1, 0, 1, 1, 2, 0};
    int n = sizeof(A) / sizeof(int);
    print(A, n);

    Solution().sortColors(A, n);
    print(A, n);

    return 0;
}