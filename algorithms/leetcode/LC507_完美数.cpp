//
// Created by lixiaoqing on 2023/3/6.
//

#include <iostream>

using std::cout, std::endl;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        /**
         * 方法1：枚举
         * 时间复杂度 O(sqrt(num)) ，空间复杂度 O(1)
         */
//        if (num == 1) {
//            return false;
//        }
//        int sum = 1;
//        for (int x = 2; x * x <= num; ++x) {
//            if (num % x != 0) {
//                continue;
//            }
//            if (x * x == num) {
//                sum += x;
//            } else {
//                sum += x + num / x;
//            }
//        }
//        return sum == num;

        /**
         * 方法2：数学
         * 时间复杂度 O(1) ，空间复杂度 O(1)
         */
        return num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336;
    }
};

int main() {
    std::cout << Solution().checkPerfectNumber(1) << std::endl;
    std::cout << Solution().checkPerfectNumber(7) << std::endl;
    std::cout << Solution().checkPerfectNumber(28) << std::endl;
    return 0;
}