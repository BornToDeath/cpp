//
// Created by lixiaoqing on 2023/1/9.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
//            printf("[%d, %d]\n", i, j);
            auto mid = i + ((j - i) >> 1);
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
    }
};

int main() {
    std::vector<int> nums = {1, 3, 5, 7, 9};
    int target = 0;
    std::cout << Solution().searchInsert(nums, target) << std::endl;
    return 0;
}