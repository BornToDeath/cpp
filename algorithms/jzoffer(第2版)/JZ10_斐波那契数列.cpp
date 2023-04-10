//
// Created by lixiaoqing on 2023/3/9.
//

#include <iostream>

class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int a = 0, b = 1, temp;
        for (int i = 2; i <= n; ++i) {
            temp = (a + b) % 1000000007;
            a = b;
            b = temp;
        }
        return b;
    }
};

int main() {
    std::cout << Solution().fib(48) << std::endl;
    return 0;
}