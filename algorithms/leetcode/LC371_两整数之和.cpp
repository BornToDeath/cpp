//
// Created by lixiaoqing on 2022/12/9.
//

#include <iostream>

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            // 转为无符号数，否则可能溢出
            unsigned int carry = (unsigned int) (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};

int main() {
    std::cout << Solution().getSum(39, -328) << std::endl;
    std::cout << Solution().getSum(-1, 1) << std::endl;
    std::cout << Solution().getSum(-12, -8) << std::endl;
    return 0;
}