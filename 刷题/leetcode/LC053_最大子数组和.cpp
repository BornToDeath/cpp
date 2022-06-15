//
// Created by lixiaoqing on 2022/6/15.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int sum = 0, max = nums[0];
        for (auto &num: nums) {
            sum += num;
            max = std::max(max, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return max;
    }
};