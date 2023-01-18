//
// Created by lixiaoqing on 2022/8/25.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        /**
         * 方法1：先归并，再找中位数
         * 时间复杂度 O(m + n) ，空间复杂度 O(m + n)
         */
//        int m = nums1.size(), n = nums2.size();
//        std::vector<int> v(m + n);
//        int i = 0, j = 0;
//        while (i < m && j < n) {
//            if (nums1[i] < nums2[j]) {
//                v[i + j] = nums1[i];
//                ++i;
//            } else {
//                v[i + j] = nums2[j];
//                ++j;
//            }
//        }
//        while (i < m) {
//            v[i + j] = nums1[i];
//            ++i;
//        }
//        while (j < n) {
//            v[i + j] = nums2[j];
//            ++j;
//        }
//        return (m + n) % 2 == 1 ? v[(m + n) / 2] : (v[(m + n) / 2] + v[(m + n) / 2 - 1]) / 2.0;

        /**
         * 方法2：无需归并，维护两个指针，查找到中位数的位置即可
         * 时间复杂度 O(m + n) ，空间复杂度 O(1)
         */
        int a, b, i = 0, j = 0, m = nums1.size(), n = nums2.size();
        for (int k = 0; k <= (m + n) / 2; ++k) {
            a = b;
            if (i < m && (j >= n || nums1[i] < nums2[j])) {
                b = nums1[i++];
            } else {
                b = nums2[j++];
            }
        }
        return ((m + n) & 0x1) == 1 ? b : (a + b) / 2.0;

        /**
         * 方法3：第 k 小数解法
         * 参考：https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-2/
         * 时间复杂度 O(log(m+n)) ，空间复杂度 O(1)
         */
//        int m = nums1.size(), n = nums2.size();
//        if ((m + n) % 2 == 1) {
//            // 奇数时，k = (m + n + 1) / 2
//            return getKth(nums1, 0, m - 1, nums2, 0, n - 1, (m + n + 1) / 2);
//        } else {
//            // 偶数时，有两个 k ，k1 = (m + n + 1) / 2 , k2 = (m + n + 2) / 2
//            int val1 = getKth(nums1, 0, m - 1, nums2, 0, n - 1, (m + n + 1) / 2);
//            int val2 = getKth(nums1, 0, m - 1, nums2, 0, n - 1, (m + n + 2) / 2);
//            return (val1 + val2) / 2.0;
//        }
    }

private:
    // 获取第 k 小的数，k 从 1 开始
    int getKth(vector<int> &nums1, int start1, const int end1, vector<int> &nums2, int start2, const int end2, int k) {
        int len1 = end1 - start1 + 1, len2 = end2 - start2 + 1;
        // 如果 nums1 比 nums2 长，颠倒下，保证 nums1 比 nums2 短
        if (len1 > len2) {
            return getKth(nums2, start2, end2, nums1, start1, end1, k);
        }
        // 如果 nums1 是空，直接返回 nums2 中第 k 小元素
        if (len1 == 0) {
            return nums2[start2 + k - 1];
        }
        // k为1时，即取第1小的元素，取两个数组中最小的元素
        if (k == 1) {
            return std::min(nums1[start1], nums2[start2]);
        }
        // 比较每个数组中第 k/2 个数的大小
        int pos1 = start1 + std::min(len1, k / 2) - 1;
        int pos2 = start2 + std::min(len2, k / 2) - 1;
        if (nums1[pos1] < nums2[pos2]) {
            return getKth(nums1, pos1 + 1, end1, nums2, start2, end2, k - (pos1 - start1 + 1));
        } else {
            return getKth(nums1, start1, end1, nums2, pos2 + 1, end2, k - (pos2 - start2 + 1));
        }
    }
};


int main() {
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};
    std::cout << Solution().findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
}