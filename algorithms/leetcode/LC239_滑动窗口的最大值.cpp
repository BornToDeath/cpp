//
// Created by lixiaoqing on 2023/8/7.
//

#include <vector>
#include <deque>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        /*
         * 方法：借助双端队列。
         * 1. 队列负责记录窗口范围内的元素，并且降序排列；由于队列中记录的都是窗口内的元素，所以他们都是窗口内第一大、第二大...的树；
         * 2. 保证队列中只记录窗口范围内元素的数的方法是：右边进一个，左边出一个；
         * 3. 由于队列头部中的较大元素并不一定在窗口内，所以需要进行判断。
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        std::vector<int> ans;
        std::deque<int> d;
        for (int i = 0; i < nums.size(); ++i) {
            while (!d.empty() && nums[i] >= nums[d.back()]) {
                d.pop_back();
            }
            d.emplace_back(i);
            while (!d.empty() && i - d.front() >= k) {
                d.pop_front();
            }
            if (i >= k - 1) {
                ans.push_back(nums[d.front()]);
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto ans = Solution().maxSlidingWindow(nums, 3);
    for (auto n: ans) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
    return 0;
}