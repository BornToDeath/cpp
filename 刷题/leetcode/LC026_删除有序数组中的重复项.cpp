//
// Created by lixiaoqing on 2022/8/11.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        /**
         * 方法1：利用 std::unique 算法
         */
//        auto it = std::unique(nums.begin(), nums.end());
//        return std::distance(nums.begin(), it);

        /**
         * 方法2：自己写删除重复元素的逻辑
         */
        int pos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[pos]) {
                nums[++pos] = nums[i];
            }
        }
        return pos + 1;
    }
};

int main() {
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::cout << Solution().removeDuplicates(nums) << std::endl;
    return 0;
}