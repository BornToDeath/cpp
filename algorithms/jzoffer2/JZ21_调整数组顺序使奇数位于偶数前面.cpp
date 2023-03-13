//
// Created by lixiaoqing on 2023/3/13.
//

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> exchange(vector<int> &nums) {
        for (int i = 0, j = nums.size() - 1; i < j;) {
            while (i < j && (nums[i] & 1) == 1) {
                ++i;
            }
            while (i < j && (nums[j] & 1) == 0) {
                --j;
            }
            if (i < j) {
                std::swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
        return nums;
    }
};