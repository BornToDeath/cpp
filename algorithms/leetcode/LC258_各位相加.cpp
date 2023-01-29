//
// Created by lixiaoqing on 2023/1/29.
//

#include <iostream>

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

int main() {
    std::cout << Solution().addDigits(10) << std::endl;
    std::cout << Solution().addDigits(38) << std::endl;
    return 0;
}