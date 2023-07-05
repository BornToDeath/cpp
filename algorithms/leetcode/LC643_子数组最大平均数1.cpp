//
// Created by boss on 2023/7/4.
//
#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        int maxSum = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            maxSum = std::max(maxSum, sum);
        }
        return maxSum * 1.0 / k;
    }
};

int main() {
    std::vector<int> nums = {0, 4, 0, 3, 2};
    int k = 1;
    std::cout << Solution().findMaxAverage(nums, k) << std::endl;
    return 0;
}