//
// Created by lixiaoqing on 2022/3/28.
//

class Solution {
public:
    int jumpFloorII(int number) {
        /**
         * 方法1：递归
         */
//        if (number <= 1) {
//            return 1;
//        }
//        return 2 * jumpFloorII(number - 1);

        /**
         * 方法2：循环
         */
        int res = 1;
        for (int i = 2; i <= number; ++i) {
            res *= 2;
        }
        return res;
    }
};