//
// Created by lixiaoqing on 2023/4/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        /*
         * 方法: 排序 + 双指针
         * 时间复杂度 O(n ^ 2) , 空间复杂度 O(logn)
         */
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        const int size = nums.size();
        for (int i = 0; i < size - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1, k = size - 1; j < k;) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // 过滤与前一个数相同的数
                    do {
                        ++j;
                    } while (j <= k && nums[j] == nums[j - 1]);
                    --k;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    nums = {-2, 0, 0, 2, 2};
    auto ans = Solution().threeSum(nums);
    for (auto &arr : ans) {
        for (auto n: arr) {
            std::cout << n << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}