//
// Created by lixiaoqing on 2022/4/1.
//

#include <iostream>
#include <bitset>

void printBinary(int num) {
    std::cout << std::bitset<8>(num) << std::endl;
}

class Solution {
public:
    int Add(int num1, int num2) {
        int sum, carry;
        do {
            // 不进位相加
            sum = num1 ^ num2;
            // 计算进位
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        } while (carry != 0);
        return sum;
    }
};

int main() {
    printBinary(-10);
    std::cout << sizeof(int) << std::endl;
    std::cout << Solution().Add(10, 20) << std::endl;
    return 0;
}