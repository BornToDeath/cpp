//
// Created by lixiaoqing on 2023/1/29.
//

#include <iostream>

class Solution {
public:
    bool isUgly(int n) {
        /**
         * 方法1：数学计算：循环除 5、3、2
         * 时间复杂度 O(logn) ，空间复杂度 O(1)
         */
        if (n <= 0) {
            return false;
        }
        while (n % 5 == 0) {
            n /= 5;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }
};

int main() {
    std::cout << Solution().isUgly(1) << std::endl;
    std::cout << Solution().isUgly(6) << std::endl;
    std::cout << Solution().isUgly(10) << std::endl;
    std::cout << Solution().isUgly(14) << std::endl;
    return 0;
}