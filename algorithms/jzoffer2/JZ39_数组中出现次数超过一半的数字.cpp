//
// Created by lixiaoqing on 2023/3/17.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }
        int count = 0, num = nums[0];
        for (auto n: nums) {
            n == num ? ++count : --count;
            if (count < 0) {
                count = 0;
                num = n;
            }
        }
        return num;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    std::cout << Solution().majorityElement(nums) << std::endl;
    return 0;
}