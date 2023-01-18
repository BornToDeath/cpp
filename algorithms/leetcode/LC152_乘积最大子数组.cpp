//
// Created by lixiaoqing on 2022/7/5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        /**
         * 方法1：动态规划。由于存在负数，所以会导致最大的变成最小的，最小的变成最大的，所以需要维护两个数组。
         * maxF[i+1] 表示以第 nums[i+1] 个元素结尾的最大乘积，minF[i+1] 表示第 nums[i+1] 个元素结尾的最小乘积。
         *   maxF[i+1] = std::max(maxF[i] * nums[i+1], minF[i] * nums[i+1], nums[i+1]);
         *   minF[i+1] = std::min(maxF[i] * nums[i+1], minF[i] * nums[i+1], nums[i+1]);
         */
//        std::vector<int> maxF(nums), minF(nums);
//        for (int i = 1; i < nums.size(); ++i) {
//            maxF[i] = std::max(maxF[i - 1] * nums[i], std::max(minF[i - 1] * nums[i], nums[i]));
//            minF[i] = std::min(maxF[i - 1] * nums[i], std::min(minF[i - 1] * nums[i], nums[i]));
//        }
//        return *max_element(maxF.begin(), maxF.end());

        /**
         * 方法2：在方法1的基础上，进行优化。
         */
        int max = 1, min = 1, ans = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); ++i) {
            int x = max;
            max = std::max(max * nums[i], std::max(min * nums[i], nums[i]));
            min = std::min(x * nums[i], std::min(min * nums[i], nums[i]));
            ans = std::max(ans, max);
        }
        return ans;
    }
};

int main() {
//    std::vector<int> nums = {2, 3, -2, 4};
//    std::vector<int> nums = {-2, 0, -1};
//    std::vector<int> nums = {0, 2};
//    std::vector<int> nums = {-2, 3, -4};
//    std::vector<int> nums = {3, -1, 4};
//    std::vector<int> nums = {3, -1, 4, -1};
    std::vector<int> nums = {-4, -3, -2};
    std::cout << Solution().maxProduct(nums) << std::endl;
    return 0;
}