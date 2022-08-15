//
// Created by lixiaoqing on 2022/8/13.
//

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        /**
         * 方法1：对于每个元素，分别计算其大于其的左边最大值与右边最大值。不AC，时间超限
         * 时间复杂度 O(n^2) ，空间复杂度 O(1)
         */
//        auto leftMax = [&height](int pos) -> int {
//            auto max = height[pos];
//            while (--pos >= 0) {
//                if (height[pos] > max) {
//                    max = height[pos];
//                }
//            }
//            return max;
//        };
//        auto rightMax = [&height](int pos) -> int {
//            auto max = height[pos];
//            while (++pos < height.size()) {
//                if (height[pos] > max) {
//                    max = height[pos];
//                }
//            }
//            return max;
//        };
//        int ans = 0;
//        for (int i = 1; i < height.size() - 1; ++i) {
//            ans += std::min(leftMax(i), rightMax(i)) - height[i];
//        }
//        return ans;

        /**
         * 方法2：在方法1的基础上进行优化。动态规划，预先计算左边最大值和右边最大值
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        if (height.empty()) {
//            return 0;
//        }
//        int size = height.size();
//        // leftMax[i] 表示 i 下标元素左边部分的最大值，rightMax[j] 表示 j 下标元素右边部分的最大值
//        std::vector<int> leftMax(size), rightMax(size);
//        for (int i = 0; i < size; ++i) {
//            if (i == 0) {
//                leftMax[0] = height[0];
//            } else {
//                leftMax[i] = std::max(leftMax[i - 1], height[i]);
//            }
//        }
//        for (int i = size - 1; i >= 0; --i) {
//            if (i == size - 1) {
//                rightMax[i] = height[i];
//            } else {
//                rightMax[i] = std::max(rightMax[i + 1], height[i]);
//            }
//        }
//        int ans = 0;
//        for (int i = 0; i < size; ++i) {
//            ans += std::min(leftMax[i], rightMax[i]) - height[i];
//        }
//        return ans;

        /**
         * 方法3：单调栈
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         * 参考：https://leetcode.cn/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode-solution-tuvc/
         */
//        if (height.empty()) {
//            return 0;
//        }
//        // 栈记录元素下标，自栈底至栈顶递减
//        std::stack<int> stack;
//        int ans = 0;
//        for (int i = 0; i < height.size(); ++i) {
//            while (!stack.empty() && height[i] >= height[stack.top()]) {
//                int base = stack.top();
//                stack.pop();
//                if (stack.empty()) {
//                    // 无法构成一个可接水区域
//                    break;
//                }
//                // 可以构成一个可接水区域
//                int j = stack.top();
//                ans += (i - j - 1) * (std::min(height[i], height[j]) - height[base]);
//            }
//            stack.push(i);
//        }
//        return ans;

        /**
         * 方法4：双指针（容易理解的解法）
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        int ans = 0;
        int max = 0; // 标记雨水高度
        for (int i = 0, j = height.size() - 1; i < j; ) {
            // 只要小于雨水高度，就可以接雨水
            while (i < j && height[i] <= max) {
                ans += max - height[i];
                ++i;
            }
            while (i < j && height[j] <= max) {
                ans += max - height[j];
                --j;
            }
            max = std::min(height[i], height[j]);
        }
        return ans;

        /**
         * 方法5：双指针（官方解法）
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        int ans = 0;
//        // 分别左边部分最大值和右边部分最大值
//        int leftMax = 0, rightMax = 0;
//        for (int i = 0, j = height.size() - 1; i < j;) {
//            leftMax = std::max(leftMax, height[i]);
//            rightMax = std::max(rightMax, height[j]);
//            if (height[i] < height[j]) {
//                ans += leftMax - height[i];
//                ++i;
//            } else {
//                ans += rightMax - height[j];
//                --j;
//            }
//        }
//        return ans;
    }
};

int main() {
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//    std::vector<int> height = {4, 2, 0, 3, 2, 5};
    std::cout << Solution().trap(height) << std::endl;
}