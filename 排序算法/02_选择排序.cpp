//
// Created by lixiaoqing on 2021/10/13.
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
    void selectSort(std::vector<int> &arr) {
//        /**
//         * 方法1：从小到大。每次选最小的放前面
//         */
//        for (int i = 0; i < arr.size(); ++i) {
//            auto minIndex = i;
//            for (int j = i + 1; j < arr.size(); ++j) {
//                if (arr[j] < arr[minIndex]) {
//                    minIndex = j;
//                }
//            }
//            if (i != minIndex) {
//                auto temp = arr[i];
//                arr[i] = arr[minIndex];
//                arr[minIndex] = temp;
//            }
//            printArray(arr);
//        }

        /**
         * 方法2：从小到大。每次选最大的放后面
         */
        for (int i = arr.size() - 1; i >= 0; --i) {
            auto maxIndex = i;
            for (int j = 0; j < i; ++j) {
                if (arr[j] > arr[maxIndex]) {
                    maxIndex = j;
                }
            }
            if (i != maxIndex) {
                auto temp = arr[i];
                arr[i] = arr[maxIndex];
                arr[maxIndex] = temp;
            }
            printArray(arr);
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {10, 4, 2, 56, 7, 8, 20};
    solution.selectSort(nums);
    return 0;
}