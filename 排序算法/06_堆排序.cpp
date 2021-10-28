//
// Created by lixiaoqing on 2021/10/14.
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
     * 堆排序。
     * 升序排序需要构建大顶堆，降序排序需要构建小顶堆。
     * @param arr
     */
    void heapSort(std::vector<int> &arr) {
        /**
         * 方法1：升序排序（构建大顶堆）
         */
        // 1. 构建大顶堆
        for (int i = arr.size() / 2 - 1; i >= 0; --i) {
            // 从最后一个非叶子节点开始，自下向上、自右至左调整堆结构
            bigHeapAdjust(arr, i, arr.size());
        }

        // 2. 将堆顶元素移至数组尾部，并调整堆
        for (int i = arr.size() - 1; i >= 0; --i) {
            auto temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            bigHeapAdjust(arr, 0, i);
        }
        printArray(arr);

//        /**
//         * 方法2：降序排序（构建小顶堆）
//         */
//        // 1. 构建小顶堆
//        for (int i = arr.size() / 2 - 1; i >= 0; --i) {
//            smallHeapAdjust(arr, i, arr.size());
//        }
//        for (int i = arr.size() - 1; i >= 0; --i) {
//            auto temp = arr[i];
//            arr[i] = arr[0];
//            arr[0] = temp;
//            smallHeapAdjust(arr, 0, i);
//        }
//        printArray(arr);
    }

private:
    /**
     * 大顶堆调整
     * @param arr  堆
     * @param root 堆中待调整的元素索引
     * @param len  待调整的堆长度
     */
    void bigHeapAdjust(std::vector<int> &arr, int root, int len) {
        while (root < len) {
            // 孩子结点
            int child = root * 2 + 1;
            if (child >= len) {
                break;
            }
            // 判断左右孩子哪个值较大
            if (child + 1 < len && arr[child] < arr[child + 1]) {
                ++child;
            }
            // 判断孩子是否大于自己
            if (arr[child] <= arr[root]) {
                // 说明以 root 为根的堆已经是大顶堆，无需再向下调整
                break;
            }
            // 交换
            auto temp = arr[root];
            arr[root] = arr[child];
            arr[child] = temp;
            // 将孩子赋给自己，继续向下调整
            root = child;
        }
    }

    /**
     * 小顶堆调整
     * @param arr
     * @param root
     * @param len
     */
    void smallHeapAdjust(std::vector<int> &arr, int root, int len) {
        while (root < len) {
            int child = root * 2 + 1;
            if (child >= len) {
                break;
            }
            if (child + 1 < len && arr[child] > arr[child + 1]) {
                ++child;
            }
            if (arr[child] >= arr[root]) {
                break;
            }
            auto temp = arr[root];
            arr[root] = arr[child];
            arr[child] = temp;
            root = child;
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {7, 6, 5, 4, 3, 2, 10, 1};
    solution.heapSort(nums);
    return 0;
}
