//
// Created by lixiaoqing on 2022/12/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(std::vector<int> &arr) {
    for (auto num : arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        /**
         * 方法1：数组排序后一分为二，然后逐个取
         * 时间复杂度 O(nlogn)，空间复杂度 O(n)
         */
//        if (nums.empty()) {
//            return;
//        }
//        std::sort(nums.begin(), nums.end());
//        const int size = nums.size();
//        std::vector<int> temp;
//        int i, j;
//        if (size % 2 == 1) {
//            // 长度是奇数时，先将首位元素入队
//            temp.emplace_back(nums.front());
//            i = 1;
//            j = (size + 1) / 2;
//        } else {
//            // 长度是偶数时
//            i = 0;
//            j = size / 2;
//        }
//
//        // 将数组一分为二，先逐个取后半部分，再逐个取前半部分
//        while (j < size) {
//            temp.emplace_back(nums[j++]);
//            temp.emplace_back(nums[i++]);
//        }
//
//        // 偶数时再将数组反转
//        if (size % 2 == 0) {
//            std::reverse(temp.begin(), temp.end());
//        }
//
//        // 赋值到原数组
//        nums.assign(temp.begin(), temp.end());

        /**
         * 方法2：方法1写法上的优化，更简洁
         * 时间复杂度 O(nlogn)，空间复杂度 O(n)
         */
//        if (nums.empty()) {
//            return;
//        }
//        auto temp = nums;
//        std::sort(temp.begin(), temp.end());
//        int n = nums.size(), x = (n + 1) / 2;
//        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, --j, --k) {
//            nums[i] = temp[j];
//            if (i + 1 < n) {
//                nums[i + 1] = temp[k];
//            }
//        }

        /**
         * 方法3：快速选择 + 三路排序
         * 参考：https://leetcode.cn/problems/wiggle-sort-ii/solution/yi-bu-yi-bu-jiang-shi-jian-fu-za-du-cong-onlognjia/
         */
        if (nums.empty()) {
            return;
        }
        int n = nums.size(), x = (n + 1) / 2, mid = x - 1;

        // 取中位数
        std::nth_element(nums.begin(), nums.begin() + mid, nums.end());

        // 将中位数放在中间，形成这样的数组：[小于部分，等于部分，大于部分]
        // eg: {5, 4, 5, 5, 6, 5, 6, 6}
        for (int k = 0, i = 0, j = n - 1; k <= j; k++) {
            if (nums[k] > nums[mid]) {
                while (j > k && nums[j] > nums[mid]) {
                    j--;
                }
                swap(nums[k], nums[j--]);
            }
            if (nums[k] < nums[mid]) {
                swap(nums[k], nums[i++]);
            }
        }

        // 组合成摆动序列
        auto temp = nums;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, --j, --k) {
            nums[i] = temp[j];
            if (i + 1 < n) {
                nums[i + 1] = temp[k];
            }
        }
    }
};

int main() {
    std::vector<int> nums = {1, 5, 1, 1, 6, 4};
//    std::vector<int> nums = {4, 5, 5, 6};
    nums = {5, 5, 5, 6, 6, 6, 4, 5};
    Solution().wiggleSort(nums);
    print(nums);
    return 0;
}