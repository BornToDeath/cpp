//
// Created by lixiaoqing on 2022/5/30.
//

class Solution {
public:
    /**
     *
     * @param A int整型一维数组
     * @param n int A数组长度
     * @return int整型
     */
    int singleNumber(int *A, int n) {
        int num = 0;
        for (int i = 0; i < n; ++i) {
            num ^= A[i];
        }
        return num;
    }
};