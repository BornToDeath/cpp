//
// Created by lixiaoqing on 2022/5/12.
//

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int findPeakElement(vector<int> &nums) {
        /**
         * 方法1：逐个比较。时间复杂度O(n)
         */
//        if (nums.empty()) {
//            return -1;
//        }
//        if (nums.size() == 1 || nums[0] > nums[1]) {
//            return 0;
//        }
//        if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
//            return nums.size() - 1;
//        }
//        for (int i = 1; i < nums.size() - 1; ++i) {
//            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
//                return i;
//            }
//        }
//        return -1;

        /**
         * 方法2：向高处靠拢，时间复杂度O(logn)
         */
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            auto mid = (right - left) / 2 + left;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    std::vector<int> nums = {2, 4, 1, 2, 7, 8, 4};
    printf("%d\n", Solution().findPeakElement(nums));
    return 0;
}