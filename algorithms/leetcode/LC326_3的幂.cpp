//
// Created by lixiaoqing on 2022/9/5.
//

class Solution {
public:
    bool isPowerOfThree(int n) {
        /**
         * 方法1：循环除
         */
//        while (n && n % 3 == 0) {
//            n /= 3;
//        }
//        return n == 1;

        /**
         * 方法2：约数法
         * 在32位整数中，3的幂最大数是3486784401，判断n是否是此数的约束
         */
        return n > 0 && 3486784401 % n == 0;
    }
};