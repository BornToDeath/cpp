//
// Created by lixiaoqing on 2023/2/15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        /**
         * 方法：一次遍历
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int max = 0, count = 0;
        for (auto c: nums) {
            if (c == 0) {
                max = std::max(max, count);
                count = 0;
            } else {
                ++count;
            }
        }
        return std::max(max, count);
    }
};

int main() {
    std::vector<int> nums = {0, 1, 1, 1, 1, 0};
    std::cout << Solution().findMaxConsecutiveOnes(nums) << std::endl;
    return 0;
}