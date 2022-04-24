//
// Created by lixiaoqing on 2022/4/24.
//

#include <iostream>
#include <vector>

inline void printArray(const std::vector<int> &nums) {
    std::for_each(nums.begin(), nums.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
}

inline void swap(std::vector<int> &nums, int i, int j) {
    auto temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void quick_sort(std::vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left;
    int j = right;
    while (i < j) {
        while (i < j && nums[j] > nums[left]) {
            --j;
        }
        while (i < j && nums[i] <= nums[left]) {
            ++i;
        }

        if (i < j) {
            swap(nums, i, j);
        }
    }
    swap(nums, i, left);
    quick_sort(nums, left, i - 1);
    quick_sort(nums, i + 1, right);
}

/**
 * 快速排序，从小到大
 * @param nums
 */
void quick_sort(std::vector<int> &nums) {
    quick_sort(nums, 0, nums.size() - 1);
}

int main() {
    std::vector<int> nums = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    quick_sort(nums);
    printArray(nums);
    return 0;
}