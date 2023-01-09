//
// Created by lixiaoqing on 2023/1/9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        /**
         * 方法1：双指针
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        int pos = 0;
//        for (auto e: nums) {
//            if (e != val) {
//                nums[pos++] = e;
//            }
//        }
//        return pos;

        /**
         * 方法2：双指针优化：避免元素重新赋值的操作
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            while (i <= j && nums[i] != val) {
                ++i;
            }
            while (i <= j && nums[j] == val) {
                --j;
            }
            if (i < j) {
                std::swap(nums[i], nums[j]);
            }
        }
        return i;
    }
};

int main() {
    std::vector<int> arr = {3, 3, 3, 3};
    int val = 3;
    std::cout << Solution().removeElement(arr, val) << std::endl;
    return 0;
}