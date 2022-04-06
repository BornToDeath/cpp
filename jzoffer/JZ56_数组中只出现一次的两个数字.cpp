//
// Created by lixiaoqing on 2022/4/1.
//

#include <iostream>
#include <vector>
#include <bitset>
#include <sys/stat.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int> &array) {
        /**
         * 方法1：使用 std::bitset ，但是空间复杂度不满足题目要求
         */
//        std::bitset<1000000> bs;
//        for (const auto num: array) {
//            if (bs[num]) {
//                bs[num] = false;
//            } else {
//                bs[num] = true;
//            }
//        }
//        std::vector<int> res;
//        for (int i = 0; i < bs.size(); ++i) {
//            if (bs[i]) {
//                res.emplace_back(i);
//            }
//        }
//        return res;

        /**
         * 方法2：异或运算：空间复杂度O(1)
         * 如果只有一个数字仅出现一次，其余都出现两次，则所有数字异或的结果就是那个仅出现一次的数字。
         * 此题中，有两个数字只出现一次，所有数字异或的结果一定非0，其二进制表示中一定有某一位为1，
         * 可根据这一位是否为1，将数组分为两部分，则两部分的所有数字分别做异或，得到的两个结果就是要求的两个结果。
         */
        // 异或结果
        int xorRes = 0;
        for (const auto num: array) {
            xorRes ^= num;
        }
        // 找出分割数组的标志位
        int flag = 1;
        while (!(flag & xorRes)) {
            flag <<= 1;
        }
        int a = 0, b = 0;
        for (const auto num: array) {
            if (num & flag) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        if (a < b) {
            return {a, b};
        } else {
            return {b, a};
        }
    }
};

int main() {
//    std::vector<int> array = {1, 2, 3, 3, 2, 9};
    std::vector<int> array = {3, 6};
    auto res = Solution().FindNumsAppearOnce(array);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
    return 0;
}