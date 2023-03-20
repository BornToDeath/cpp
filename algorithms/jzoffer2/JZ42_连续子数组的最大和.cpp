//
// Created by lixiaoqing on 2023/3/20.
//

#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }
        int max = nums[0], sum = 0;
        for (auto n: nums) {
            sum += n;
            max = std::max(max, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << Solution().maxSubArray(nums) << std::endl;
    return 0;
}