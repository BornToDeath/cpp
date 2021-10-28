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
    void quitSort(std::vector<int> &arr) {
        realQuitSort(arr, 0, arr.size() - 1);
    }

private:
    void realQuitSort(std::vector<int> &arr, int left, int right) {
        if (left >= right) {
            return;
        }
        auto base = arr[left];
        int i = left;
        int j = right;
        while (i < j) {
            // 从后向前
            while (arr[j] > base && i < j) {
                --j;
            }
            // 从前向后
            while (arr[i] <= base && i < j) {
                ++i;
            }
            // 交换左右两个指针的值
            if (i < j) {
                auto temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // 交换基准和临界点的值
        arr[left] = arr[i];
        arr[i] = base;
        printArray(arr);

        // 递归排序
        realQuitSort(arr, left, i - 1);
        realQuitSort(arr, i + 1, right);
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {7, 6, 5, 4, 3, 2, 1, 15, 12};
    solution.quitSort(nums);
    return 0;
}