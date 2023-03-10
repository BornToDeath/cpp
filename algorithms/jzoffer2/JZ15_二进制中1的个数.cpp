//
// Created by lixiaoqing on 2023/3/10.
//

class Solution {
public:
    int hammingWeight(uint32_t n) {
        /**
         * 方法1：n & (n-1)
         */
        int ans = 0;
        while (n) {
            ++ans;
            n &= n - 1;
        }
        return ans;

        /**
         * 方法2：std::bitset
         */
        std::bitset<32> b(n);
        return b.count();
    }
};