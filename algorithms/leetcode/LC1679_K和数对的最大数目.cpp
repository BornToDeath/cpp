//
// Created by boss on 2023/7/4.
//

#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        int ans = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0, j = nums.size() - 1; i < j;) {
            if (nums[i] + nums[j] == k) {
                ++ans;
                ++i;
                --j;
            } else if (nums[i] + nums[j] > k) {
                --j;
            } else {
                ++i;
            }
        }
        return ans;
    }
};