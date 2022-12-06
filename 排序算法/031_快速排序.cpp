//
// Created by lixiaoqing on 2022/4/24.
//

#include <iostream>
#include <vector>
#include <stack>

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

int quick_sort2(std::vector<int> &arr, int start, int end) {
    if (start >= end) {
        return start;
    }
    int base = arr[start];
    int i = start, j = end;
    while (i < j) {
        while (i < j && arr[j] > base) {
            --j;
        }
        while (i < j && arr[i] <= base) {
            ++i;
        }
        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[start], arr[i]);
    return i;
}

/**
 * 快速排序，从小到大
 * @param nums
 */
void quick_sort(std::vector<int> &nums) {
    /**
     * 方法1：递归写法
     */
//    quick_sort(nums, 0, nums.size() - 1);

    /**
     * 方法2：非递归写法
     */
    if (nums.empty()) {
        return;
    }
    std::stack<std::pair<int, int>> _stack;
    _stack.push({0, nums.size() - 1});
    while (!_stack.empty()) {
        auto interval = _stack.top();
        _stack.pop();
        int pos = quick_sort2(nums, interval.first, interval.second);
        if (pos > interval.first) {
            _stack.push({interval.first, pos - 1});
        }
        if (pos < interval.second) {
            _stack.push({pos + 1, interval.second});
        }
    }
}

int main() {
    std::vector<int> nums = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    quick_sort(nums);
    printArray(nums);
    return 0;
}