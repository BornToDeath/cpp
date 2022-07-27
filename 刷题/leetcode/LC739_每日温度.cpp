//
// Created by lixiaoqing on 2022/7/26.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        /**
         * 方法1：暴力枚举，时间复杂度 O(n^2) 。不AC，时间复杂度超限
         */
//        int size = temperatures.size();
//        std::vector<int> ans(size, 0);
//        for (int i = 0; i < size; ++i) {
//            for (int j = i + 1; j < size; ++j) {
//                if (temperatures[j] > temperatures[i]) {
//                    ans[i] = j - i;
//                    break;
//                }
//            }
//        }
//        return ans;

        /**
         * 方法2：暴力枚举，时间复杂度 O(nm) ，空间复杂度 O(m) ，其中 n 是 ans 的大小，m 是 dp 的大小
         */
//        int size = temperatures.size();
//        std::vector<int> ans(size, 0);
//        std::vector<int> dp(101, INT_MAX);  // 存放温度在 temperatures 中的下标
//        for (int i = size - 1; i >= 0; --i) {
//            int minIndex = INT_MAX;  // 存放下个较大温度的下标
//            for (int j = temperatures[i] + 1; j < dp.size(); ++j) {
//                minIndex = std::min(minIndex, dp[j]);
//            }
//            if (minIndex != INT_MAX) {
//                ans[i] = minIndex - i;
//            }
//            dp[temperatures[i]] = i;
//        }
//        return ans;

        /**
         * 方法3：利用栈
         */
        int size = temperatures.size();
        std::vector<int> ans(size, 0);
        std::stack<int> stack;
        for (int i = 0; i < size; ++i) {
            if (stack.empty()) {
                stack.push(i);
                continue;
            }
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                ans[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {73, 74, 75, 71, 69, 72, 76, 73};
//    std::vector<int> nums = {30, 40, 50, 60};
    auto ans = Solution().dailyTemperatures(nums);
    for (auto num: ans) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}