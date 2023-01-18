//
// Created by lixiaoqing on 2022/8/9.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        /**
         * 方法1：排序，然后比较
         * 时间复杂度 O(nlogn) ，空间复杂度 O(n)
         */
//        if (nums.empty()) {
//            return 0;
//        }
//        std::vector<int> dp(nums);
//        std::sort(dp.begin(), dp.end());
//        int start = 0, end = nums.size() - 1;
//        while (start <= end && nums[start] == dp[start]) {
//            ++start;
//        }
//        while (start <= end && nums[end] == dp[end]) {
//            --end;
//        }
//        return end - start + 1;

        /**
         * 方法2：双指针
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         * 思路：同时从前往后和从后往前遍历，分别得到子数组的右边界和左边界
         *   寻找右边界：从前往后遍历，并记录最大值 max ，如果 max > nums[j] ，说明 nums[j] 的位置不正确，属于需要排序的子数组中的元素，因此将右边界更新为 j ，然后更新 max ；
         *   寻找左边界：从后往前遍历，并记录最小值 min ，如果 min < nums[i] ，说明 nums[i] 的位置不正确，属于需要排序的子数组中的元素，因此将左边界更新为 i ，然后更新 min ；
         * 这样遍历之后，i 左边的元素都比 min 小，j 右边的元素都比 max 大，介于 <i, j> 之间的元素就是所求的需要排序的子数组。
         * 参考：https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/solution/si-lu-qing-xi-ming-liao-kan-bu-dong-bu-cun-zai-de-/
         */
        if (nums.empty()) {
            return 0;
        }
        int start = 0, end = -1;
        int len = nums.size(), min = nums[len - 1], max = nums[0];
        for (int i = 0; i < len; ++i) {
            // 从左向右计算右边界
            if (nums[i] < max) {
                end = i;
            } else {
                max = nums[i];
            }
            // 从右到左计算左边界
            if (nums[len - 1 - i] > min) {
                start = len - 1 - i;
            } else {
                min = nums[len - 1 - i];
            }
        }
        return end - start + 1;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::cout << Solution().findUnsortedSubarray(nums) << std::endl;
    return 0;
}