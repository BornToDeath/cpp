//
// Created by lixiaoqing on 2022/6/20.
//

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        for (int i = 0, j = nums.size() - 1; i <= j;) {
            auto mid = (j - i) / 2 + i;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < nums[j]) {
                if (target > nums[mid] && target <= nums[j]) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            } else {
                if (target >= nums[i] && target < nums[mid]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            }
        }
        return -1;
    }

};