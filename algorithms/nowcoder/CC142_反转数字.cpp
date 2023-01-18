//
// Created by lixiaoqing on 2022/6/6.
//

#include <iostream>
#include <climits>

class Solution {
public:
    /**
     *
     * @param x int整型
     * @return int整型
     */
    int reverse(int x) {
        /**
         * 方法1：
         */
//        int pos = 1;
//        if (x < 0) {
//            pos = -1;
//            x = -x;
//        }
//        int res = 0;
//        while (x) {
//            if ((pos > 0 && INT_MAX / 10 < res) || (pos < 0 && INT_MIN / 10 > res * -1)) {
//                return 0;
//            }
//            res = res * 10 + x % 10;
//            x /= 10;
//        }
//        return res * pos;

        /**
         * 方法2：这种方法当 x=2123456789 牛客不通过，why????
         */
//        int res = 0;
//        while (x != 0) {
//            int temp = res * 10 + x % 10;
//            // 如果反过来不能得到res说明产生溢出
//            if ((temp - x % 10) / 10 != res) {
//                return 0;
//            }
//            res = temp;
//            x /= 10;
//        }
//        return res;

        /**
         * 方法3：
         */
        int res = 0;
        while (x != 0) {
            int pop = x % 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop >= 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop <= -8)) {
                return 0;
            }
            res = res * 10 + pop;
            x /= 10;
        }
        return res;
    }
};

int main() {
    std::cout << INT_MAX << std::endl;
    std::cout << INT_MIN << std::endl;
    std::cout << Solution().reverse(2123456789) << std::endl;
    return 0;
}