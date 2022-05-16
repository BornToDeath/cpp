//
// Created by lixiaoqing on 2022/5/15.
//

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> &arr) {
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
}

class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        /**
         * 方法1：利用快排的思想。但是这种方法不AC（超时），但是官方也是这种解法-_-
         */
//        if (K < 1 || K > n) {
//            return -1;
//        }
//        return findKth(a, 0, n - 1, K);

        /**
         * 方法2：利用 std::sort
         */
        if (K < 1 || K > n) {
            return -1;
        }
        std::sort(a.begin(), a.end(), std::greater<int>());
        return a[K - 1];
    }

private:
    int findKth(vector<int> &a, int start, int end, int K) {
        if (K < 1) {
            return -1;
        }
        // index 左边的都比它大，右边的都比它小
        auto index = quick_sort(a, start, end);
        if (index - start + 1 == K) {
            return a[index];
        } else if (index - start + 1 > K) {
            return findKth(a, start, index - 1, K);
        } else {
            return findKth(a, index + 1, end, K - (index - start + 1));
        }
    }

    /**
     * 快速排序，降序排序
     * @param a
     * @param start
     * @param end
     */
    int quick_sort(std::vector<int> &a, int start, int end) {
        int i = start;
        int j = end;
        while (i < j) {
            while (i < j && a[j] <= a[start]) {
                --j;
            }
            while (i < j && a[i] > a[start]) {
                ++i;
            }
            if (i < j) {
                std::swap(a[i], a[j]);
            }
        }
        std::swap(a[start], a[i]);
        return i;
    }
};

int main() {
    std::vector<int> nums = {10, 10, 9, 9, 8, 7, 5, 6, 4, 3, 4, 2};
//    std::vector<int> nums = {1, 3, 5, 2, 2};
    std::cout << Solution().findKth(nums, nums.size(), 3) << std::endl;
}