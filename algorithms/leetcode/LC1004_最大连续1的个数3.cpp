//
// Created by lixiaoqing on 2023/7/12.
//

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        /*
         * 方法1: 滑动窗口. 窗口只增大不减小, 所以最终 r - l 就是窗口的最大值
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
//        int l = 0, r = 0;
//        while (r < nums.size()) {
//            if (nums[r++] == 0) {
//                --k;
//            }
//            if (k < 0 && nums[l++] == 0) {
//                ++k;
//            }
//        }
//        return r - l;

        /*
         * 方法2: 滑动窗口. 问题转换为: 找出一个最长的子数组, 该数组内最多允许有 k 个 0
         *   1. r 主动右移: 当 nums[r] = 0 说明窗口内增加了一个 0 ;
         *   2. l 被动右移: 判断此时窗口内 0 的个数, 如果超过了 k , 则 l 右移, 直至窗口内 0 的个数不超过 k ;
         *   3. 滑动窗口的最大长度即为所求.
         * 参考: https://leetcode.cn/problems/max-consecutive-ones-iii/solution/fen-xiang-hua-dong-chuang-kou-mo-ban-mia-f76z/
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        int ans = 0;
        for (int l = 0, r = 0, n = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) {
                ++n;
            }
            while (n > k) {
                if (nums[l++] == 0) {
                    --n;
                }
            }
            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

//    nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
//    k = 3;

//    nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
//    k = 3;

//    nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1};
//    k = 0;

    std::cout << Solution().longestOnes(nums, k) << std::endl;
    return 0;
}