//
// Created by lixiaoqing on 2022/12/19.
//

#include <iostream>
#include <vector>


/**
 * 快速选择算法。是一种从一个无序数组中找到第k小元素的算法，从原理上与快速排序有关。
 * 时间复杂度 O(n) ，空间复杂度 O(1) 。
 * 参考：https://blog.csdn.net/zpznba/article/details/86504046
 */

int partition(std::vector<int> &arr, int i, int j);

/**
 * 查找第 k 小的元素，k 从 1 开始
 * 时间复杂度 O(n) ，空间复杂度 O(1) 。
 * @param arr
 * @param k
 * @return
 */
int findKthSmallest(std::vector<int> &arr, int k) {
    if (k <= 0 || k > arr.size()) {
        return -1;
    }
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int index = partition(arr, l, r);
        if (index + 1 == k) {
            return arr[index];
        } else if (index > k) {
            r = index - 1;
        } else {
            l = index + 1;
        }
    }
    return -1;
}

/**
 * 查找第 k 大的元素，k 从 1 开始
 * 时间复杂度 O(n) ，空间复杂度 O(1) 。
 * @param arr
 * @param k
 * @return
 */
int findKthLargest(std::vector<int> &arr, int k) {
    if (k <= 0 || k > arr.size()) {
        return -1;
    }
    k = arr.size() + 1 - k;
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int index = partition(arr, l, r);
        if (index + 1 == k) {
            return arr[index];
        } else if (index > k) {
            r = index - 1;
        } else {
            l = index + 1;
        }
    }
    return -1;
}

// 快速排序，返回一趟排序后基准节点的下标
int partition(std::vector<int> &arr, int left, int right) {
    if (left >= right) {
        return left;
    }
    auto base = arr[left];
    int i = left, j = right;
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
    std::swap(arr[left], arr[i]);
    return i;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << findKthSmallest(arr, 5) << std::endl;
    std::cout << findKthLargest(arr, 5) << std::endl;
    return 0;
}