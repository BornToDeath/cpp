//
// Created by lixiaoqing on 2021/10/13.
//

#include <iostream>
#include <vector>

inline void printArray(std::vector<int> &arr) {
    std::for_each(arr.begin(), arr.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
}

class Solution {
public:
    /**
     * 归并排序
     * @param arr
     */
    void mergeSort(std::vector<int> &arr) {
        /**
         * 方法1：递归。从上到下
         */
//        realMergeSort(arr, 0, arr.size() - 1);

        /**
         * 方法2：迭代。从下到上
         */

        auto step = 1;
        do {
            step *= 2;
            for (int i = 0; i < arr.size(); i += step) {
                auto end = std::min(i + step - 1, (int) arr.size() - 1);
                mergeTwoArray(arr, i, end);
            }
        } while (step < arr.size());
    }

private:
    void realMergeSort(std::vector<int> &arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = (right - left) / 2 + left;

        // 分
        realMergeSort(arr, left, mid);
        realMergeSort(arr, mid + 1, right);

        // 治
        mergeTwoArray(arr, left, right);
    }

    void mergeTwoArray(std::vector<int> &arr, int left, int right) {
        if (left >= right) {
            return;
        }
        std::vector<int> nums(right - left + 1);
        auto pos = 0;
        auto mid = (right - left) / 2 + left;
        auto i = left;
        auto j = mid + 1;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                nums[pos++] = arr[i++];
            } else {
                nums[pos++] = arr[j++];
            }
        }
        while (i <= mid) {
            nums[pos++] = arr[i++];
        }
        while (j <= right) {
            nums[pos++] = arr[j++];
        }
        for (const auto num: nums) {
            arr[left++] = num;
        }
        printArray(arr);
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {7, 6, 5, 4, 3, 2, 1, 8};
    solution.mergeSort(nums);
    return 0;
}