//
// Created by lixiaoqing on 2023/4/16.
//

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        /*
         * 方法1: 遍历, 不AC, 时间超限
         * 时间复杂度 O(n^2) , 空间复杂度 O(1)
         */
//        int count = 0;
//        for (int i = 0; i < nums.size(); ++i) {
//            for (int j = i + 1; j < nums.size(); ++j) {
//                if (nums[i] > nums[j]) {
//                    ++count;
//                }
//            }
//        }
//        return count;

        /*
         * 方法2: 借助归并排序的思想
         * 时间复杂度 O(nlogn) , 空间复杂度 O(n)
         */
        if (nums.empty()) {
            return 0;
        }
        binary_sort(nums, 0, nums.size() - 1);
        return count;
    }

private:
    void binary_sort(std::vector<int> &nums, int beg, int end) {
        if (beg >= end) {
            return;
        }
        auto mid = ((end - beg) >> 1) + beg;
        binary_sort(nums, beg, mid);
        binary_sort(nums, mid + 1, end);
        std::vector<int> temp(end - beg + 1);
        int i = beg, j = mid + 1, k = 0;
        while (i <= mid && j <= end) {
            if (nums[i] > nums[j]) {
                count += end - j + 1;
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= end) {
            temp[k++] = nums[j++];
        }
        std::copy(temp.begin(), temp.end(), nums.begin() + beg);
    }

private:
    int count{0};
};

int main() {
    std::vector<int> nums = {7, 5, 6, 4};
    std::cout << Solution().reversePairs(nums) << std::endl;
    for (auto num : nums) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}