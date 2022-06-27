//
// Created by lixiaoqing on 2022/6/26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        /**
         * 方法1：计数
         */
//        int count0 = 0, count1 = 0;
//        for (auto num: nums) {
//            if (num == 0) {
//                ++count0;
//            } else if (num == 1) {
//                ++count1;
//            }
//        }
//        std::fill(nums.begin(), nums.begin() + count0, 0);
//        std::fill(nums.begin() + count0, nums.begin() + count0 + count1, 1);
//        std::fill(nums.begin() + count0 + count1, nums.end(), 2);

        /**
         * 方法2（推荐）：三路快排
         */
        int start = 0, end = nums.size() - 1;
        for (int i = 0; i <= end;) {
            if (nums[i] == 0) {
                std::swap(nums[i++], nums[start++]);
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[end--]);
            } else {
                ++i;
            }
        }
    }
};

int main() {
    std::vector<int> nums = {2, 2, 2, 0, 0, 1, 0};
    Solution().sortColors(nums);
    for (auto num: nums) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}