//
// Created by lixiaoqing on 2022/7/13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        /**
         * 方法1：利用 std::sort
         */
//        std::sort(nums.begin(), nums.end(), std::greater<int>());
//        return nums[k - 1];

        /**
         * 方法2：在1的基础上优化，左右部分不用都排序，只对我们需要的元素所在的部分进行排序
         */
//        return findKth(nums, 0, nums.size() - 1, k);

        /**
         * 方法3：堆排序。先将全部元素建大顶堆，然后逐一删除至k
         */
//        int len = nums.size();
//        for (int i = len / 2 - 1; i >= 0; --i) {
//            big_heap_adjust(nums, i, len);
//        }
//        for (int i = 0; i < k; ++i) {
//            swap(nums[0], nums[--len]);
//            big_heap_adjust(nums, 0, len);
//        }
//        return nums[len];

        /**
         * 方法4：堆排序。先用k个元素建小顶堆，然后将剩余元素添加至堆中，最终堆顶元素即所求元素
         */
        for (int i = k / 2 - 1; i >= 0; --i) {
            small_heap_adjust(nums, i, k);
        }
        for (int i = k; i < nums.size(); ++i) {
            // 只有比堆顶元素大的元素才可以被添加到堆中
            if (nums[0] < nums[i]) {
                swap(nums[0], nums[i]);
                small_heap_adjust(nums, 0, k);
            }
        }
        return nums[0];
    }

private:
    // 调整小顶堆
    void small_heap_adjust(std::vector<int> &nums, int root, int len) {
        while (root * 2 + 1 < len) {
            int child = root * 2 + 1;
            if (child + 1 < len && nums[child] > nums[child + 1]) {
                ++child;
            }
            if (nums[root] <= nums[child]) {
                break;
            }
            swap(nums[root], nums[child]);
            root = child;
        }
    }

    // 调整大顶堆
    void big_heap_adjust(std::vector<int> &nums, int root, int len) {
        while (root * 2 + 1 < len) {
            int child = root * 2 + 1;
            if (child + 1 < len && nums[child] < nums[child + 1]) {
                ++child;
            }
            if (nums[root] >= nums[child]) {
                break;
            }
            swap(nums[root], nums[child]);
            root = child;
        }
    }

    int findKth(std::vector<int> &nums, int left, int right, int k) {
        // pos 左边的都比 k 大，右边的都比 k 小
        auto pos = quick_sort(nums, left, right);
        if (pos == k - 1) {
            return nums[pos];
        } else if (pos > k - 1) {
            return findKth(nums, left, pos - 1, k);
        } else {
            return findKth(nums, pos + 1, right, k);
        }
    }

    // 从大到小排序
    int quick_sort(std::vector<int> &nums, int left, int right) {
        if (left > right) {
            return -1;
        }
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] <= nums[left]) {
                --j;
            }
            while (i < j && nums[i] >= nums[left]) {
                ++i;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[left], nums[i]);
        return i;
    }
};

int main() {
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    std::cout << Solution().findKthLargest(nums, 2) << std::endl;
}