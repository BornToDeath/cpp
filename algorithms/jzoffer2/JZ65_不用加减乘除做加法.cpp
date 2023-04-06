//
// Created by lixiaoqing on 2023/4/6.
//

#include <iostream>

class Solution {
public:
    int add(int a, int b) {
        /*
         * 位运算
         * 时间复杂度 O(log(max_int)) , 空间复杂度 O(1)
         */
        while (b) {
            unsigned int t = a & b;
            a ^= b;
            b = t << 1;
        }
        return a;
    }
};

int main() {
    std::cout << Solution().add(3, 5) << std::endl;
    std::cout << Solution().add(-3, 5) << std::endl;
    std::cout << Solution().add(-10, -120) << std::endl;
    std::cout << Solution().add(INT_MIN, INT_MAX) << std::endl;
    return 0;
}