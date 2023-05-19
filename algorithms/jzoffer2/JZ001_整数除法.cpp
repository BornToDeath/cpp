//
// Created by lixiaoqing on 2023/4/11.
//

#include <iostream>

class Solution {
public:
    int divide(int a, int b) {
        /*
         * 方法: 用减法来模拟除法
         * 参考: https://leetcode.cn/problems/xoh6Oh/solution/by-demouo-bnhc/
         */
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        const bool flag = (a > 0 && b > 0) || (a < 0 && b < 0);
        if (a > 0) {
            a = -a;
        }
        if (b > 0) {
            b = -b;
        }
        auto ans = div(a, b);
        return flag ? -ans : ans;
    }

private:
    /**
     * 快速减实现除法. a, b 均为负数, 返回值也为负值
     * @param a
     * @param b
     * @return
     */
    int div(int a, int b) {
        int ans = 0;
        while (a <= b) {  // a 的绝对值大, 说明 a 够减
            int count = -1;  // a 肯定能减一次 b , 同时为避免内存溢出, 使用负值进行计算
            int temp = b;
            while (temp >= INT_MIN / 2 && a <= temp + temp) {
                temp += temp;
                count += count;
            }
            a -= temp;
            ans += count;
        }
        return ans;
    }
};

int main() {
    printf("[%d, %d]\n", INT_MIN, INT_MAX);
    std::cout << Solution().divide(-27, 3) << std::endl;
    std::cout << Solution().divide(INT_MAX, 1) << std::endl;
    std::cout << Solution().divide(INT_MIN, 1) << std::endl;
    return 0;
}