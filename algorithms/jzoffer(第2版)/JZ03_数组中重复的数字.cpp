//
// Created by lixiaoqing on 2023/3/7.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        /**
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        for (int i = 0; i < nums.size();) {
            if (i == nums[i]) {
                ++i;
            } else if (nums[i] == nums[nums[i]]) {
                return nums[i];
            } else {
                std::swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};

int main() {
    std::vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    std::cout << Solution().findRepeatNumber(nums) << std::endl;
    return 0;
}