//
// Created by lixiaoqing on 2023/4/11.
//

#include <string>

class Solution {
public:
    bool isUnique(string str) {
        /*
         * 方法1: 利用数组
         * 时间复杂度 O(n) , 空间复杂度 O(N) , 其中 N=26
         */
        //        char dp[26] = {0};
        //        for (auto c: astr) {
        //            if (dp[c - 'a'] == '1') {
        //                return false;
        //            }
        //            dp[c - 'a'] = '1';
        //        }
        //        return true;

        /*
         * 方法2: 位运算
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        int flag = 0;
        for (auto c: astr) {
            if (flag & (1 << (c - 'a'))) {
                return false;
            }
            flag |= 1 << (c - 'a');
        }
        return true;
    }
};