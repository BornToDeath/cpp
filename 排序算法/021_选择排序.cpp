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

/**
 * 选择排序，从小到大
 * @param nums
 */
void select_sort(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        auto minIndex = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        swap(nums, i, minIndex);
    }
}

int main() {
    std::vector<int> nums = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    select_sort(nums);
    printArray(nums);
    return 0;
}