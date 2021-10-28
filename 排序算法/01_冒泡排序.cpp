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
    void bubbleSort(std::vector<int> &arr) {
//        /**
//         * 方法1：从小到大。
//         * 从前向后，每次挑出最大的放队尾。
//         */
//        for (int i = arr.size() - 1; i > 0; --i) {
//            for (int j = 0; j < i; ++j) {
//                if (arr[j] > arr[j + 1]) {
//                    auto temp = arr[j + 1];
//                    arr[j + 1] = arr[j];
//                    arr[j] = temp;
//                }
//            }
//            printArray(arr);
//        }
//        std::cout << "================================" << std::endl;

        /**
         * 方法2：从小到大
         * 从后向前，每次挑选最小的放前面。
         */
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = arr.size() - 1; j > i; --j) {
                if (arr[j] < arr[j - 1]) {
                    auto temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                }
            }
            printArray(arr);
        }

    }
};


int main() {
    std::vector<int> nums = {3, 1, 4, 8, 7, 1, 10, 22, 2};
    Solution solution;
    solution.bubbleSort(nums);
    return 0;
}