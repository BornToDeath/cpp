//
// Created by boss on 2023/5/8.
//

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        /*
         * 方法1: 双重循环, 不 AC
         * 时间复杂度 O(n^2) , 空间复杂度 O(1)
         */
//        int max = 0;
//        for (int i = 0; i < heights.size(); ++i) {
//            const int height = heights[i];
//            int width = 1;
//            for (int j = i - 1; j >= 0 && heights[j] >= height; --j) {
//                ++width;
//            }
//            for (int j = i + 1; j < heights.size() && heights[j] >= height; ++j) {
//                ++width;
//            }
//            max = std::max(max, width * height);
//        }
//        return max;


    }
};

int main() {
    std::vector<int> nums = {2, 1, 5, 6, 2, 3};
//    nums = {2, 4};
//    nums = {2, 0, 2};
//    nums = {2, 1, 2};
    std::cout << Solution().largestRectangleArea(nums) << std::endl;
    return 0;
}