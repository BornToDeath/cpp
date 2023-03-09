//
// Created by lixiaoqing on 2023/3/9.
//

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minArray(vector<int> &numbers) {
        /**
         * 二分查找
         * 时间复杂度: 一般 O(logn), 最坏 O(n) ；空间复杂度 O(1)
         */
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            auto m = l + ((r - l) >> 1);
            if (numbers[m] < numbers[r]) {
                r = m;
            } else if (numbers[m] > numbers[r]) {
                l = m + 1;
            } else {
                --r;
            }

        }
        return numbers[l];
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    nums = {4, 5, 1, 2, 3};
    nums = {2, 2, 2, 0, 1};
    nums = {1, 0, 1, 1, 1};
//    nums = {1, 1, 1, 0, 1};
    std::cout << Solution().minArray(nums) << std::endl;
    return 0;
}