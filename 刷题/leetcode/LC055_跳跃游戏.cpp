//
// Created by lixiaoqing on 2022/6/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        /**
         * 方法：贪心算法。记录最远能够到达的位置，同时每个位置判断是否可达
         */
        // 记录最远能到达的位置
        int max = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (max >= n - 1) {
                return true;
            } else if (max < i) {
                return false;
            }
            max = std::max(max, i + nums[i]);
        }
        return false;
    }
};

int main() {
//    std::vector<int> nums = {2, 3, 1, 1, 4};
//    std::vector<int> nums = {3, 0, 0, 0, 4};
//    std::vector<int> nums = {0, 2, 3};
//    std::vector<int> nums = {0};
    std::vector<int> nums = {2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6, 3, 1, 2, 2, 1, 2, 6, 5, 3, 1, 2, 2,
                             6, 4, 2, 4, 3, 0, 0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0, 7, 9, 3, 4, 6, 6, 5, 8,
                             9, 3, 4, 3, 7, 0, 4, 9, 0, 9, 8, 4, 3, 0, 7, 7, 1, 9, 1, 9, 4, 9, 0, 1, 9, 5, 7, 7, 1, 5,
                             8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6};
    std::cout << std::boolalpha << Solution().canJump(nums) << std::endl;
    return 0;
}