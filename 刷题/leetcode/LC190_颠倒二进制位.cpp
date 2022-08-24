//
// Created by lixiaoqing on 2022/8/24.
//

#include <cstdint>
#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /**
         * 方法1：逐位反转
         */
//        uint32_t ans = 0;
//        for (int i = 0; i < 32 && n > 0; ++i) {
//            ans = (ans << 1) | (n & 1);
//            n >>= 1;
//        }
//        return ans;

        /**
         * 方法2：位分治
         * 时间复杂度 O(1) ，空间复杂度 O(1)
         */
        uint32_t M1 = 1431655765;  // 01010101 01010101 01010101 01010101
        uint32_t M2 = 858993459;   // 00110011 00110011 00110011 00110011
        uint32_t M4 = 252645135;   // 00001111 00001111 00001111 00001111
        uint32_t M8 = 16711935;    // 00000000 11111111 00000000 11111111
        uint32_t ans = 0;
        // 相邻1位反转
        n = ((n & M1) << 1) | ((n >> 1) & M1);
        // 相邻2位反转
        n = ((n & M2) << 2) | ((n >> 2) & M2);
        // 相邻4位反转
        n = ((n & M4) << 4) | ((n >> 4) & M4);
        // 相邻8位反转
        n = ((n & M8) << 8) | ((n >> 8) & M8);
        // 相邻16位反转
        return (n << 16) | (n >> 16);
    }
};

int main() {
    uint32_t n = 10;
    std::cout << Solution().reverseBits(n) << std::endl;
    return 0;
}