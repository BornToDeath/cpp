//
// Created by lixiaoqing on 2023/3/10.
//

class Solution {
public:
    double myPow(double x, int n) {
        /**
         * 快速幂
         * 时间复杂度 O(logn) ，空间复杂度 O(1)
         */
        long nn = n;
        bool pos = nn >= 0;
        nn = abs(nn);  // 注意：如果 n 为 INT_MIN, 此时 ads(n) 会有问题！
        double ans = 1;
        while (nn) {
            if ((nn & 1) == 1) {
                ans *= x;
            }
            x *= x;
            nn >>= 1;
        }
        return pos ? ans : 1 / ans;
    }
};