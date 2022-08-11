//
// Created by lixiaoqing on 2022/8/11.
//

#include <iostream>

class Solution {
public:
    int reverse(int x) {
        /**
         * 方法1：从后向前逐个翻转
         */
        const int MIN = std::numeric_limits<int>::min() / 10;
        const int MAX = std::numeric_limits<int>::max() / 10;
        int ans = 0;
        while (x) {
            if (ans < MIN || ans > MAX || ans == MIN && x % 10 < -8 || ans == MAX && x % 10 > 7) {
                return 0;
            }
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;

        /**
         * 方法2：直接翻转，如果本次翻转的结果除以10和上次的不一样，则说明有溢出。但是不AC，因为平台检测到有溢出
         */
//        int ans = 0;
//        while (x) {
//            auto e = ans * 10 + x % 10;
//            if (e / 10 != ans) {
//                return 0;
//            }
//            ans = e;
//            x /= 10;
//        }
//        return ans;
    }
};

int main() {
    std::cout << Solution().reverse(123) << std::endl;
    std::cout << Solution().reverse(-123) << std::endl;
    std::cout << INT_MAX << std::endl;
    std::cout << std::numeric_limits<int>::max() << std::endl;
    std::cout << INT_MIN << std::endl;
    std::cout << Solution().reverse(INT_MAX) << std::endl;
    std::cout << Solution().reverse(INT_MIN) << std::endl;
    return 0;
}