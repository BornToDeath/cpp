//
// Created by lixiaoqing on 2022/6/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i != j) {
                    std::swap(nums[i], nums[j]);
                }
                ++j;
            }
        }
    }
};

int main() {
    std::vector<int> nums = {0, 1, 0, 3, 12};
    Solution().moveZeroes(nums);
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
    return 0;
}