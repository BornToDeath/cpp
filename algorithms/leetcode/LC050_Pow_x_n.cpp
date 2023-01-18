//
// Created by lixiaoqing on 2022/8/17.
//

#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        /**
         * 方法1：调用 pow 库函数
         */
//        return pow(x, n);

        /**
         * 方法2：快速幂。迭代实现
         */
        bool pos = true;
        long nn = n;
        if (nn < 0) {
            nn = -nn;
            pos = false;
        }
        double ans = 1;
        while (nn) {
            if ((nn & 1) == 1) {
                ans *= x;
            }
            x *= x;
            nn >>= 1;
        }
        return pos ? ans : 1 / ans;

        /**
         * 方法3：快速幂。递归实现
         */
//        if (n == 0) {
//            return 1;
//        }
//        long nn = n;
//        if (n < 0) {
//            nn = -nn;
//        }
//        auto y = myPow(x, nn / 2);
//        double res = y * y * ((nn & 1) == 0 ? 1 : x);
//        return n > 0 ? res : 1 / res;
    }
};

int main() {
    std::cout << Solution().myPow(3, 4) << std::endl;
    std::cout << Solution().myPow(3, 5) << std::endl;
    std::cout << Solution().myPow(5, 4) << std::endl;
    std::cout << Solution().myPow(2, -2) << std::endl;
    return 0;
}