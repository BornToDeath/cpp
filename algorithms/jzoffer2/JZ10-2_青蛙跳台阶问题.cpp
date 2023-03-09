//
// Created by lixiaoqing on 2023/3/9.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int numWays(int n) {
        /**
         * F(n) = F(n - 1) + F(n - 2), 其实就是斐波那契数列
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int a = 1, b = 1, c;
        for (int i = 2; i <= n; ++i) {
            c = (a + b) % 1000000007;
            a = b;
            b = c;
        }
        return b;
    }
};

int main() {
    std::cout << Solution().numWays(95) << std::endl;
    return 0;
}
