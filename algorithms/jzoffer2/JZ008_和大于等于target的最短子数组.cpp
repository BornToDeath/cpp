//
// Created by lixiaoqing on 2023/4/19.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        /*
         * 方法: 滑动窗口
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        int sum = 0, len = nums.size() + 1;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while (i <= j && sum >= target) {
                len = std::min(len, j - i + 1);
                sum -= nums[i++];
            }
        }
        return len > nums.size() ? 0 : len;
    }
};

int main() {
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    nums = {1, 4, 4};
    nums = {1, 1, 1, 1, 1, 1, 1, 1};
    nums = {1, 2, 3, 4, 5};
    int target = 11;
    std::cout << Solution().minSubArrayLen(target, nums) << std::endl;
    return 0;
}
