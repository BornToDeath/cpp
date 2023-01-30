//
// Created by lixiaoqing on 2023/1/30.
//

#include <iostream>

class Solution {
public:
    bool canWinNim(int n) {
        /**
         * 方法1：数学计算
         * 找规律，凡是 4 的倍数就铁输
         */
        return n % 4 != 0;

        /**
         * 方法2：动态规划，超时
         */
//        if (n <= 3) {
//            return true;
//        }
//        return !canWinNim(n - 1) || !canWinNim(n - 2) || !canWinNim(n - 3);
    }
};

int main() {
    std::cout << std::boolalpha;
    for (int i = 1; i <= 20; ++i) {
        std::cout << i << ": " << Solution().canWinNim(i) << std::endl;
    }
    return 0;
}