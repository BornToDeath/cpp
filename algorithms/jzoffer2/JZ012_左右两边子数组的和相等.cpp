//
// Created by lixiaoqing on 2023/4/20.
//

#include <iostream>
#include <vector>
#include <numeric>

using std::vector;


class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        /*
         * 方法1: 两个数组，分别表示「左边部分的和」和「右边部分的和」
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
//        const int size = nums.size();
//        std::vector<int> left(size), right(size);
//        for (int i = 1; i < size; ++i) {
//            left[i] = left[i - 1] + nums[i - 1];
//            right[size - i - 1] = right[size - i] + nums[size - i];
//        }
//        for (int i = 0; i < size; ++i) {
//            if (left[i] == right[i]) {
//                return i;
//            }
//        }
//        return -1;

        /*
         * 方法2: 方法1的优化
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
//        const int size = nums.size();
//        std::vector<int> right(size);
//        for (int i = size - 2; i >= 0; --i) {
//            right[i] = right[i + 1] + nums[i + 1];
//        }
//        int left = 0;
//        for (int i = 0; i < size; ++i) {
//            if (left == right[i]) {
//                return i;
//            }
//            left += nums[i];
//        }
//        return -1;

        /*
         * 方法3: 左 = 右 , 即: sum_left = total_sum - num[i] - sum_left,
         *                即: 2 * sum_left + nums[i] = total_sum
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (left * 2 + nums[i] == total) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};


int main() {
    std::vector<int> nums = {1, 7, 3, 6, 5, 6};
    nums = {2, 1, -1};
    nums = {1, 2, 3};
    std::cout << Solution().pivotIndex(nums) << std::endl;
    return 0;
}