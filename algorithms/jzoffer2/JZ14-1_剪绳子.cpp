//
// Created by lixiaoqing on 2023/3/10.
//

#include <iostream>

class Solution {
public:
    int cuttingRope(int n) {
        /**
         * 将 n 拆解为若干个 3 和 2 ，此时乘积最大
         * 时间复杂度 O(1) ，空间复杂度 O(1)
         */
        if (n <= 3) {
            return n - 1;
        }
        int x = n / 3, y = n % 3;
        if (y == 0) {
            return pow(3, x);
        } else if (y == 1) {
            return pow(3, x-1) * 4;
        } else {
            return pow(3, x) * 2;
        }
    }
};

int main() {
    std::cout << Solution().cuttingRope(4) << std::endl;
    std::cout << Solution().cuttingRope(10) << std::endl;
    std::cout << Solution().cuttingRope(11) << std::endl;
    return 0;
}