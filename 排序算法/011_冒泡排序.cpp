//
// Created by lixiaoqing on 2022/4/21.
//

#include <iostream>
#include <vector>

void printArray(const std::vector<int> &nums) {
    std::for_each(nums.begin(), nums.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
}

inline void swap(std::vector<int> &nums, int i, int j) {
    auto temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

/**
 * 冒泡排序，从小到大
 * @param nums
 */
void bubble_sort(std::vector<int> &nums) {
    for (int i = nums.size() - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums, j, j + 1);
            }
        }
        printArray(nums);
    }
}

int main() {
    std::vector<int> nums = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    bubble_sort(nums);

    return 0;
}