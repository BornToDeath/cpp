//
// Created by lixiaoqing on 2022/6/21.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        for (int left = 0, right = nums.size() - 1; left <= right;) {
            auto mid = (right - left) / 2 + left;
            if (nums[mid] == target) {
                int i = mid, j = mid;
                while (i >= 0 && nums[i] == target) {
                    --i;
                }
                while (j < nums.size() && nums[j] == target) {
                    ++j;
                }
                return {i + 1, j - 1};
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return {-1, -1};
    }
};