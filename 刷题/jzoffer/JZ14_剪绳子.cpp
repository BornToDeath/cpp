//
// Created by lixiaoqing on 2022/4/14.
//
#include <iostream>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int cutRope(int n) {
        if (n == 2) {
            return 1;
        }
        // 将n拆解为若干个3和2，此时乘积最大
        int sum = 1;
        while (n > 1) {
            auto step = 0;
            if (n - 3 >= 2 || n - 3 == 0) {
                step = 3;
            } else if (n - 2 >= 0) {
                step = 2;
            }
            n -= step;
            sum *= step;
        }
        return sum;
    }
};

int main() {
    std::cout << Solution().cutRope(15) << std::endl;
    return 0;
}