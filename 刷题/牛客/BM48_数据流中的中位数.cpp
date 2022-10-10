//
// Created by lixiaoqing on 2022/10/10.
//

#include <algorithm>
#include <vector>


class Solution {
public:
    void Insert(int num) {
        nums.push_back(num);
        std::sort(nums.begin(), nums.end());
    }

    double GetMedian() {
        int i = nums.size() / 2, j = (nums.size() - 1) / 2;
        return (nums[i] + nums[j]) / 2.0;
    }

private:
    std::vector<int> nums;
};