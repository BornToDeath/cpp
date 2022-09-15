//
// Created by lixiaoqing on 2022/9/15.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        /**
         * 方法1：二分查找的思想
         * 时间复杂度 O(logn) ，空间复杂度 O(1)
         */
//        int start = 0, end = nums.size() - 1;
//        while (start < end) {
//            auto mid = ((end - start) >> 1) + start;
//            if (mid == start) {
//                return nums[start] > nums[end] ? start : end;
//            }
//            if (nums[mid] > nums[mid - 1]) {
//                start = mid;
//            } else {
//                end = mid;
//            }
//
//        }
//        return start;

        /**
         * 方法2：方法1的逻辑优化
         * 时间复杂度 O(logn) ，空间复杂度 O(1)
         */
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            auto mid = ((end - start) >> 1) + start;
            if (nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid;
            }

        }
        return start;
    }
};

int main() {
//    std::vector<int> nums = {1, 2, 3, 1};
    std::vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    std::cout << Solution().findPeakElement(nums) << std::endl;
    return 0;
}