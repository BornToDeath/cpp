//
// Created by lixiaoqing on 2022/6/1.
//

class Solution {
public:
    /**
     *
     * @param n int整型
     * @return int整型
     */
    int climbStairs(int n) {
        int num1 = 1, num2 = 1;
        for (int i = 2; i <= n; ++i) {
            num1 += num2;
            num2 = num1 - num2;
        }
        return num1;
    }
};