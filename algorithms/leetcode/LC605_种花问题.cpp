//
// Created by lixiaoqing on 2023/6/29.
//

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        /*
         * 方法1: 贪心
         * 时间复杂度 O(n), 空间复杂度 O(1)
         */
//        if (flowerbed.empty()) {
//            return n == 0;
//        }
//        const int size = flowerbed.size();
//        if (size == 1) {
//            return n == 0 || flowerbed.front() == 0 && n == 1;
//        }
//        for (int i = 0; i < size && n > 0; ++i) {
//            if (flowerbed[i] == 1 || (i - 1 >= 0 && flowerbed[i - 1] == 1) || (i + 1 < size && flowerbed[i + 1] == 1)) {
//                continue;
//            }
//            flowerbed[i] = 1;
//            --n;
//        }
//        return n == 0;

        /*
         * 方法2: 跳格子
         * https://leetcode.cn/problems/can-place-flowers/solution/fei-chang-jian-dan-de-tiao-ge-zi-jie-fa-nhzwc/
         * 时间复杂度 O(n), 空间复杂度 O(1)
         */
        for (int i = 0; i < flowerbed.size() && n > 0;) {
            if (flowerbed[i] == 1) {
                i += 2;
            } else if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
                --n;
                i += 2;
            } else {
                i += 3;
            }
        }
        return n == 0;
    }
};

int main() {
    std::vector<int> nums = {0, 0, 1, 0, 1};
    int n = 1;
    std::cout << Solution().canPlaceFlowers(nums, n) << std::endl;
    return 0;
}