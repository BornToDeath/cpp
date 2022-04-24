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

void heap_adjust(std::vector<int> &nums, int root, int len) {
    while (root < len) {
        auto child = root * 2 + 1;
        if (child >= len) {
            break;
        }
        if (child + 1 < len && nums[child] < nums[child + 1]) {
            ++child;
        }
        if (nums[child] <= nums[root]) {
            break;
        }
        swap(nums, child, root);
        root = child;
    }
}

void heap_sort(std::vector<int> &nums) {
    const int len = nums.size();
    for (int i = len / 2 - 1; i >= 0; --i) {
        heap_adjust(nums, i, len);
    }
    for (int i = len - 1; i > 0; --i) {
        swap(nums, 0, i);
        heap_adjust(nums, 0, i);
    }
}

int main() {
    std::vector<int> nums = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    printArray(nums);
    std::cout << "---------------------------------------" << std::endl;
    heap_sort(nums);
    printArray(nums);
    return 0;
}