//
// Created by boss on 2023/5/8.
//

#include <vector>
#include <iostream>
#include <stack>

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

        /*
         * 方法2: 单调栈, 栈中记录逐渐递增的元素的下标
         * 参考：https://leetcode.cn/problems/largest-rectangle-in-histogram/solution/bao-li-jie-fa-zhan-by-liweiwei1419/
         * 时间复杂度 O(n), 空间复杂度 O(n)
         */
//        int max = 0, size = heights.size();
//        std::stack<int> s;
//        for (int i = 0; i < size; ++i) {
//            while (!s.empty() && heights[s.top()] > heights[i]) {  // 大于当前高度的元素出栈
//                auto height = heights[s.top()];
//                s.pop();
//                int width = s.empty() ? i : i - s.top() - 1;
//                max = std::max(max, height * width);
//            }
//            s.push(i);  // 栈保持递增
//        }
//        while (!s.empty()) {  // 栈中递增元素, 需要计算面积, 形如: {1, 2, 10}
//            auto height = heights[s.top()];
//            s.pop();
//            auto width = s.empty() ? size : size - s.top() - 1;
//            max = std::max(max, height * width);
//        }
//        return max;

        /*
         * 方法3: 方法2的改进，增加哨兵, 可以简化处理逻辑, 不用处理如下情况:
         *       1. 栈中元素全部弹出导致栈为空, 如 {5, 4, 1}
         *       2. 栈中元素没有处理完全导致栈不为空, 如 {1, 2, 10}
         * 时间复杂度 O(n), 空间复杂度 O(n)
         */
        int max = 0;
        std::stack<int> s;
        // 在首尾添加哨兵，认为数组首尾的矩阵高度都为 0
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                auto height = heights[s.top()];
                s.pop();
                auto width = i - s.top() - 1;
                max = std::max(max, height * width);
            }
            s.push(i);
        }
        return max;
    }
};

int main() {
    std::vector<int> nums = {2, 1, 5, 6, 2, 3};
//    nums = {2, 4};
//    nums = {2, 0, 2};
//    nums = {2, 1, 2};
//    nums = {5, 4, 1, 2, 10};
    std::cout << Solution().largestRectangleArea(nums) << std::endl;
    return 0;
}