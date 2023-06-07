//
// Created by lixiaoqing on 2023/6/7.
//

#include <iostream>
#include <vector>
#include <numeric>

using std::vector;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        // 二分查找
        auto speed = [&piles](int num) {
            int count = 0;
            for (auto n: piles) {
                count += ceil(n * 1.0 / num);
            }
            return count;
        };
        int ans = 1, i = 1, j = *std::max_element(piles.begin(), piles.end());
        while (i <= j) {
            int mid = ((j - i) >> 1) + i;
            int count = speed(mid);
            if (speed(mid) <= h) {
                j = mid - 1;
                ans = mid;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {3, 6, 7, 11};
    int k = 8;
    nums = {30, 11, 23, 4, 20};
    k = 6;
    std::cout << Solution().minEatingSpeed(nums, k) << std::endl;
    return 0;
}