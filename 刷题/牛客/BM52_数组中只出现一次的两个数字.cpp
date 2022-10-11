//
// Created by lixiaoqing on 2022/10/11.
//

#include <iostream>
#include <vector>

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
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int temp = 0;
        for (auto e: array) {
            temp ^= e;
        }
        int flag = 1;
        while (temp && (temp & flag) == 0) {
            flag <<= 1;
        }
        int a = 0, b = 0;
        for (auto e: array) {
            e & flag ? a ^= e : b ^= e;
        }
        if (a < b) {
            return {a, b};
        } else {
            return {b, a};
        }
    }
};

int main() {
    std::vector<int> nums = {3, 6};
    auto res = Solution().FindNumsAppearOnce(nums);
    for (auto e: res) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
    return 0;
}