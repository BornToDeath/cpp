//
// Created by lixiaoqing on 2022/4/14.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        /**
         * 方法1：利用数组或链表
         */
//        std::vector<bool> arr(n, false);
//        // 标识当前的报数
//        auto index = 0;
//        // 标识当前圆圈的索引
//        int i = -1;
//        int SIZE = n;
//        while (n > 0) {
//            ++i;
//            i %= SIZE;
//            if (arr[i]) {
//                continue;
//            }
//            ++index;
//            if (index == m) {
//                arr[i] = true;
//                index = 0;
//                --n;
//                // 需要在圆圈中循环 n 次
//                if (n == 0) {
//                    break;
//                }
//            }
//        }
//        return i;

        /**
         * 方法2：递归
         */
//        if (n == 1) {
//            return 0;
//        }
//        auto x = LastRemaining_Solution(n - 1, m);
//        return (x + m) % n;

        /**
         * 方法3：迭代
         */
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = (res + m) % i;
        }
        return res;
    }
};

int main() {
    std::cout << Solution().LastRemaining_Solution(10, 17) << std::endl;
    return 0;
}