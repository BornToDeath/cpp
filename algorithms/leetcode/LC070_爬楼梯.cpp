//
// Created by lixiaoqing on 2022/6/16.
//

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for (int i = 1; i < n; ++i) {
            a += b;
            b = a - b;
        }
        return a;
    }
};