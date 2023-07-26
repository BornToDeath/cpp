//
// Created by lixiaoqing on 2023/7/25.
//

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int findMin(vector<int> &nums) {
        /*
         * 方法1: 二分查找
         * 时间复杂度 O(logn), 空间复杂度 O(1)
         */
//        int ans = nums.front();
//        for (int l = 0, r = nums.size() - 1; l <= r;) {
//            int mid = ((l - r) >> 1) + r;
//            if (nums[mid] <= nums[r]) {
//                r = mid - 1;
//                ans = std::min(ans, nums[mid]);
//            } else {
//                l = mid + 1;
//            }
//        }
//        return ans;

        /*
         * 方法2: 二分查找(官方)
         * 时间复杂度 O(logn), 空间复杂度 O(1)
         */
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

int main() {
    std::vector<int> nums = {3, 4, 5, 1, 2};
    nums = {4, 5, 6, 7, 0, 1, 2};
    nums = {11, 13, 15, 17};
    nums = {3, 1, 2};
    nums = {2, 3, 1};
    nums = {0, 1};
    nums = {1, 0};
    std::cout << Solution().findMin(nums) << std::endl;
    return 0;
}