//
// Created by lixiaoqing on 2023/1/30.
//

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /**
         * 方法：二分查找
         * 时间复杂度 O(logn) ，空间复杂度 O(1)
         */
        int i = 1, j = n;
        while (i < j) {
            int mid = i + ((j - i) >> 1);
            if (isBadVersion(mid)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
};