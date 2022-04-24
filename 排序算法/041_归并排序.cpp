//
// Created by lixiaoqing on 2022/4/24.
//

#include <iostream>
#include <vector>

inline void printArray(const std::vector<int> &nums) {
    std::for_each(nums.begin(), nums.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
}

void merge(std::vector<int> &nums, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    std::vector<int> arr;
    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            arr.emplace_back(nums[i++]);
        } else {
            arr.emplace_back(nums[j++]);
        }
    }
    while (i <= mid) {
        arr.emplace_back(nums[i++]);
    }
    while (j <= end) {
        arr.emplace_back(nums[j++]);
    }
    std::move(arr.begin(), arr.end(), nums.begin() + start);
}

void merge_sort(std::vector<int> &nums, int start, int end) {
    if (start >= end) {
        return;
    }
    // 分
    auto mid = (end - start) / 2 + start;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid + 1, end);
    // 治
    merge(nums, start, mid, end);
}

/**
 * 归并排序
 */
void merge_sort(std::vector<int> &nums) {
    /**
     * 方法1：自上向下，递归
     */
//    merge_sort(nums, 0, nums.size() - 1);

    /**
     * 方法2：自下而上，迭代
     */
    const int SIZE = nums.size();
    for (int i = 2; i / 2 < SIZE; i *= 2) {
        for (int j = 0; j < SIZE; j += i) {
            merge(nums, j, j + i / 2 - 1, std::min(j + i - 1, SIZE - 1));
        }
    }
}


int main() {
    std::vector<int> nums = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    merge_sort(nums);
    printArray(nums);
    return 0;
}