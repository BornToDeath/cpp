//
// Created by lixiaoqing on 2022/6/9.
//

#include <iostream>
#include <map>

class Solution {
public:
    /**
     *
     * @param A int整型一维数组
     * @param n int A数组长度
     * @return int整型
     */
    int singleNumber(int *A, int n) {
        /**
         * 方法1：借助 std::map 。时间复杂度O(n)，空间复杂度O(n)
         */
//        std::map<int, int> _map;
//        for (int i = 0; i < n; ++i) {
//            _map[A[i]]++;
//        }
//        for (auto pair: _map) {
//            if (pair.second == 1) {
//                return pair.first;
//            }
//        }
//        return -1;

        /**
         * 方法2：各位相加，和为 3N 或 3N+1 ，然后对 3 取余。时间复杂度O(n)，空间复杂度O(1)
         */
//        int res = 0;
//        for (int i = 0; i < 32; ++i) {
//            int total = 0;
//            for (int j = 0; j < n; ++j) {
//                total += (A[j] >> i) & 0x1;
//            }
//            res |= (total % 3) << i;
//        }
//        return res;

        /**
         * 方法3：数字电路设计。时间复杂度O(n)，空间复杂度O(1)
         * 参考：https://leetcode.cn/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetc-23t6/
         */
        int a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            b = ~a & (b ^ A[i]);
            a = ~b & (a ^ A[i]);
        }
        return b;
    }
};

int main() {
    int arr[] = {1, 1, 1, 4, 5, 5, 5};
    std::cout << Solution().singleNumber(arr, sizeof(arr) / sizeof(int)) << std::endl;
    return 0;
}