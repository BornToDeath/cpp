//
// Created by lixiaoqing on 2023/2/1.
//

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        /**
         * 方法：二分查找
         */
        for (int i = 1, j = n; i <= j;) {
            auto mid = i + ((j - i) >> 1);
            auto flag = guess(mid);
            if (flag == 0) {
                return mid;
            } else if (flag == 1) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return -1;
    }
};