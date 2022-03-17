//
// Created by lixiaoqing on 2022/3/17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        /**
         * 方法1：借助 std::count
         */
//        return std::count(data.begin(), data.end(), k);

        /**
         * 方法2：借助 std::equal_range
         */
//        auto bounds = std::equal_range(data.begin(), data.end(), k);
//        return (bounds.second - bounds.first);

        /**
         * 方法3：二叉查找
         */
        if (data.empty() || k < data[0] || k > data[data.size() - 1]) {
            return 0;
        }
        return getLastK(data, k) - getFirstK(data, k) + 1;
    }

private:

    static int getFirstK(const std::vector<int> &nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = ((end - start) >> 1) + start;
            if (nums[mid] < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }

    static int getLastK(const std::vector<int> &nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = ((end - start) >> 1) + start;
            if (nums[mid] <= k) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }

};

int main() {
    std::vector<int> nums = {1, 2, 4, 5, 6, 7, 7};
//    std::cout << std::lower_bound(nums.begin(), nums.end(), 10) - nums.begin() << std::endl;
//    std::cout << std::upper_bound(nums.begin(), nums.end(), 10) - nums.begin() << std::endl;

    Solution solution;
    std::cout << solution.GetNumberOfK(nums, 3) << std::endl;
    return 0;
}