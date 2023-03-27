//
// Created by lixiaoqing on 2023/3/27.
//

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        /**
         * 双指针
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        for (int i = 0, j = nums.size() - 1; i < j;) {
            auto sum = nums[i] + nums[j];
            if (sum == target) {
                return {nums[i], nums[j]};
            } else if (sum < target) {
                ++i;
            } else {
                --j;
            }
        }
        return {};
    }
};