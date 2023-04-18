//
// Created by lixiaoqing on 2023/4/18.
//

#include <iostream>
#include <vector>
#include <queue>

using std::vector;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        /*
         * 方法1: 暴力遍历, 不AC, 时间超限
         * 时间复杂度 O(kn) , 空间复杂度 O(1)
         */
//        const int size = nums.size();
//        std::vector<int> dp(size - k + 1);
//        for (int i = 0; i < size - k + 1; ++i) {
//            dp[i] = nums[i];
//            for (int j = i; j < i + k; ++j) {
//                if (nums[j] > dp[i]) {
//                    dp[i] = nums[j];
//                }
//            }
//        }
//        return dp;

        /*
         * 方法2: 借助双端队列
         * 时间复杂度 O(n) , 空间复杂度 O(k)
         */
        std::vector<int> dp;
        std::deque<int> d;
        for (int i = 0; i < nums.size(); ++i) {
            while (!d.empty() && nums[d.back()] <= nums[i]) {
                d.pop_back();
            }
            d.push_back(i);
            while (!d.empty() && i - d.front() >= k) {
                d.pop_front();
            }
            if (i + 1 >= k) {
                dp.push_back(nums[d.front()]);
            }
        }
        return dp;
    }
};

int main() {
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
//    nums = {10, 2, 3, 4, 7};
    nums = {1, -1};
    auto ans = Solution().maxSlidingWindow(nums, 1);
    for (auto num: ans) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}