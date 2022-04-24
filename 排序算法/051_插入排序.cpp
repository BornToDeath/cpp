//
// Created by lixiaoqing on 2022/4/24.
//

#include <iostream>
#include <vector>

inline void printArray(const std::vector<int> &nums) {
    std::for_each(nums.begin(), nums.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
}

void insert_sort(std::vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] >= nums[i - 1]) {
            continue;
        }
        auto ele = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > ele) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = ele;
    }
}

int main() {
    std::vector<int> nums = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    printArray(nums);
    std::cout << "---------------------------------------" << std::endl;
    insert_sort(nums);
    printArray(nums);
    return 0;
}