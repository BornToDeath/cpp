//
// Created by lixiaoqing on 2023/2/15.
//

#include <iostream>

class Solution {
public:
    int findComplement(int num) {
        /**
         * 方法1：先找高位 1 ，后面再逐位取反
         * 时间复杂度 O(lognum) ，空间复杂度 O(1)
         */
//        int flag = 0x40000000;
//        while ((num & flag) == 0) {
//            flag >>= 1;
//        }
//        while (flag) {
//            num ^= flag;
//            flag >>= 1;
//        }
//        return num;

        /**
         * 方法2：找到高位 1 所表示的整数，然后再 -1 和 num 异或
         * 时间复杂度 O(lognum) ，空间复杂度 O(1)
         */
        int flag = 0x40000000;
        while ((num & flag) == 0) {
            flag >>= 1;
        }
        int mask = flag == 0x40000000 ? 0x7fffffff : (flag << 1) - 1;
        return num ^ mask;
    }
};

int main() {
    std::cout << Solution().findComplement(5) << std::endl;
    std::cout << Solution().findComplement(2) << std::endl;
    std::cout << Solution().findComplement(1) << std::endl;
    return 0;
}