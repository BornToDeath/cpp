//
// Created by lixiaoqing on 2022/3/28.
//

#include <iostream>

class Solution {
public:
    int jumpFloor(int number) {
        /**
         * 方法1：递归
         */
//        if (number <= 2) {
//            return number;
//        }
//        return jumpFloor(number - 1) + jumpFloor(number - 2);

        /**
         * 方法2：循环
         */
        int num1 = 0, num2 = 1;
        for (int i = 1; i <= number; ++i) {
            num2 = num1 + num2;
            num1 = num2 - num1;
        }
        return num2;
    }
};

int main() {
    std::cout << Solution().jumpFloor(40) << std::endl;
    return 0;
}