//
// Created by lixiaoqing on 2022/4/6.
//
#include <iostream>
#include <vector>

using namespace std;

void printArray(const std::vector<int> &arr) {
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
}

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        /**
         * 方法1：使用快速排序
         */
//        if (k == 0) {
//            return {};
//        }
//        std::sort(input.begin(), input.end());
//        std::vector<int> res;
//        for (int i = 0; i < k; ++i) {
//            res.emplace_back(input[i]);
//        }
//        return res;

        /**
         * 方法：使用堆排序（构建小顶堆）
         * 对整个数组构建堆，然后对堆进行k次调整，每次调整之后堆顶元素就是最小元素
         */
//        if (k == 0) {
//            return {};
//        }
//        if (input.empty() || k >= input.size()) {
//            return input;
//        }
//        std::vector<int> res;
//        for (int i = 0; i < k; ++i) {
//            smallHeapSort(input, i, input.size());
//            res.emplace_back(input[i]);
//        }
//        return res;

        /**
         * 方法3：也是使用堆排序（构建大顶堆）
         * 先构建一个只包含k个元素的大顶堆，然后向堆中添加数组中剩余的元素，最后堆中的k个元素就是最小的k个元素
         */
        if (k == 0) {
            return {};
        }
        if (input.empty() || input.size() <= k) {
            return input;
        }
        // 构建一个具有k个元素的大顶堆。从最后一个叶子节点开始调整堆
        for (int i = k / 2 - 1; i >= 0; --i) {
            bigHeapSort(input, i, k);
        }

        // 依次向堆中添加数组中剩余的元素
        for (int i = k; i < input.size(); ++i) {
            if (input[i] >= input[0]) {
                continue;
            }
            auto temp = input[0];
            input[0] = input[i];
            input[i] = temp;
            bigHeapSort(input, 0, k);
        }
        std::vector<int> res(k, 0);
        std::copy(input.begin(), input.begin() + k, res.begin());
        return res;
    }

private:
    /**
     * 小顶堆排序。从最后一个叶子节点开始，每次计算其父节点，比较该节点与其父节点的大小
     * @param arr
     * @param root
     * @param size
     */
    void smallHeapSort(vector<int> &arr, int root, int size) {
        for (int child = size - 1; child >= root; --child) {
            int parent = (child + root - 1) / 2;
            if (arr[parent] > arr[child]) {
                auto temp = arr[parent];
                arr[parent] = arr[child];
                arr[child] = temp;
            }
        }
    }

    /**
     * 大顶堆排序。从根节点开始向下调整
     * @param arr
     * @param root
     * @param size
     */
    void bigHeapSort(std::vector<int> &arr, int root, int size) {
        while (root < size) {
            auto child = root * 2 + 1;
            if (child >= size) {
                break;
            }
            if (child + 1 < size && arr[child] < arr[child + 1]) {
                ++child;
            }
            if (arr[root] >= arr[child]) {
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
    std::vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
    printArray(input);
    auto res = Solution().GetLeastNumbers_Solution(input, 4);
    printArray(res);
    return 0;
}