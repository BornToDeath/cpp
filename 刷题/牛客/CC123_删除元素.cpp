//
// Created by lixiaoqing on 2022/6/6.
//

#include <iostream>

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != elem) {
                A[pos++] = A[i];
            }
        }
        return pos;
    }
};