//
// Created by lixiaoqing on 2022/9/5.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int size = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        return size * (size + 1) / 2 - sum;
    }
};

int main() {
    std::vector<int> nums = {0, 1, 2};
    std::cout << Solution().missingNumber(nums) << std::endl;
    return 0;
}