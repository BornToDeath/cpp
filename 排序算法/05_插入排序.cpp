//
// Created by lixiaoqing on 2021/10/14.
//

#include <iostream>
#include <vector>

inline void printArray(std::vector<int> &arr) {
    std::for_each(arr.begin(), arr.end(), [](int num) {
        std::cout << num << ", ";
    });
    std::cout << std::endl;
}

class Solution {
public:
    /**
     * 插入排序
     * @param arr
     */
    void insertSort(std::vector<int> &arr) {
        for (int i = 1; i < arr.size(); ++i) {
            auto val = arr[i];
            // 找元素待插入的位置
            int index = i - 1;
            while (val < arr[index] && index >= 0) {
                // 数组元素后移
                arr[index + 1] = arr[index];
                --index;
            }
            // 插入
            arr[index + 1] = val;
            printArray(arr);
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {7, 4, 1, 10, 8, 6, 15, 2};
    solution.insertSort(nums);
    return 0;
}