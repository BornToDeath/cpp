//
// Created by lixiaoqing on 2023/3/23.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums) {
        int res = 0;
        for (auto n: nums) {
            res ^= n;
        }
        int flag = 1;
        while ((flag & res) == 0) {
            flag <<= 1;
        }
        int a = 0, b = 0;
        for (auto n : nums) {
            n & flag ? a ^= n : b ^= n;
        }
        return {a, b};
    }
};

int main() {
    std::vector<int> nums = {1, 2, 10, 4, 1, 4, 3, 3};
    auto ans = Solution().singleNumbers(nums);
    std::cout << ans[0] << ", " << ans[1] << std::endl;
    return 0;
}