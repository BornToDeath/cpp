//
// Created by lixiaoqing on 2023/3/22.
//

#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        /**
         * 方法1：借助 std::count
         * 时间复杂度 O(n) ，空间复杂度 O(1)s
         */
//        return std::count(nums.begin(), nums.end(), target);

        /**
         * 方法2：二分
         * 时间复杂度 O(logn) ，空间复杂度 O(1)
         */
//        for (int i = 0, j = nums.size() - 1; i <= j;) {
//            auto mid = i + ((j - i) >> 1);
//            if (nums[mid] == target) {
//                int count = 0;
//                for (int k = mid; k >= 0 && nums[k] == target; --k) {
//                    ++count;
//                }
//                for (int k = mid + 1; k < nums.size() && nums[k] == target; ++k) {
//                    ++count;
//                }
//                return count;
//            } else if (nums[mid] < target) {
//                i = mid + 1;
//            } else {
//                j = mid - 1;
//            }
//        }
//        return 0;

        /**
         * 方法3：std::upper_bound, std::lower_bound, 底层也是二分
         * 时间复杂度 O(logn) ，空间复杂度 O(1)
         */
        auto it1 = std::upper_bound(nums.begin(), nums.end(), target);  // > target
        auto it2 = std::lower_bound(nums.begin(), nums.end(), target);  // >= target
        return it1 - it2;
    }
};