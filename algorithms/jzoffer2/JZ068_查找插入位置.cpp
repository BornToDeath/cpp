//
// Created by lixiaoqing on 2023/5/8.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            auto mid = ((j - i) >> 1) + i;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
    }

};

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 10;
    std::cout << Solution().searchInsert(nums, target) << std::endl;
    return 0;
}