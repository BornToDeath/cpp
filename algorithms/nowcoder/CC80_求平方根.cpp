//
// Created by lixiaoqing on 2022/6/1.
//

#include <iostream>

class Solution {
public:
    /**
     *
     * @param x int整型
     * @return int整型
     */
    int sqrt(int x) {
        /**
         * 方法1：除法运算
         */
        if (x == 0) {
            return 0;
        }
        int start = 1, end = x / 2;
        while (start <= end) {
            auto mid = (end - start) / 2 + start;
            if (x / mid < mid) {
                end = mid - 1;
            } else if (x / (mid + 1) >= mid + 1) {
                start = mid + 1;
            } else {
                start = mid;
                break;
            }
        }
        return static_cast<int>(start);

        /**
         * 方法2：利用平方数的性质：连续n个奇数相加的结果一定是平方数
         */
    }
};

int main() {
    std::cout << Solution().sqrt(4) << std::endl;
    return 0;
}