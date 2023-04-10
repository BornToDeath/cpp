//
// Created by lixiaoqing on 2023/3/23.
//

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using std::vector;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        /*
         * 方法1: 求和
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
//        auto sum = std::accumulate(nums.begin(), nums.end(), 0);
//        const int n = nums.size() + 1;
//        return ((n * (n - 1)) >> 1) - sum;

        /*
         * 方法2：逐个比较
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        for (int i = 0; i < nums.size(); ++i) {
            if (i != nums[i]) {
                return i;
            }
        }
        return static_cast<int>(nums.size());
    }
};

int main() {
    std::vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << Solution().missingNumber(nums) << std::endl;
    return 0;
}