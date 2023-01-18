//
// Created by lixiaoqing on 2022/8/31.
//

#include <iostream>
#include <cstdint>
#include <bitset>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        /**
         * 方法1：与1比较并移位
         */
//        int count = 0;
//        while (n) {
//            count += n & 1;
//            n >>= 1;
//        }
//        return count;

        /**
         * 方法2：x & (x -1)
         */
//        int count = 0;
//        while (n) {
//            n &= n - 1;
//            ++count;
//        }
//        return count;

        /**
         * 方法3：借助 std::bitset
         */
        std::bitset<32> b(n);
        return b.count();
    }
};

int main() {
    std::cout << Solution().hammingWeight(0b11111111111111111111111111111101) << std::endl;
    return 0;
}