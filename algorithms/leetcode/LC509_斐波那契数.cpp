//
// Created by lixiaoqing on 2023/3/7.
//

#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
    int fib(int n) {
        /**
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        if (n <= 1) {
            return n;
        }
        int a = 0, b = 1;
        for (int i = 2; i <= n; ++i) {
            b += a;
            a = b - a;
        }
        return b;
    }
};

int main() {
    std::cout << Solution().fib(2) << std::endl;
    std::cout << Solution().fib(3) << std::endl;
    std::cout << Solution().fib(10) << std::endl;
}