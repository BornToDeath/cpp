//
// Created by lixiaoqing on 2023/5/8.
//

#include <vector>
#include <tuple>
#include <stack>
#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    int longestValidParentheses(string s) {
        /*
         * 方法1: 动态规划, dp[i] 表示 s[i] 字符结尾的最长有效括号的长度.
         *      那么, 当 s[i] = '(' 时, dp[i] = 0; 只有当 s[i] 为 ')' 时, dp[i] 才值得计算
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
//        if (s.empty()) {
//            return 0;
//        }
//        std::vector<int> dp(s.length());
//        for (int i = 1; i < s.length(); ++i) {
//            if (s[i] == ')') {
//                if (s[i - 1] == '(') {  // 形如: ...()
//                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
//                } else if (s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {  // 形如: ...))
//                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
//                }
//            }
//        }
//        return *std::max_element(dp.begin(), dp.end());

        /*
         * 方法2: 借助栈, 栈底存放「最后一个没有被匹配的右括号的下标」, 目的是方便下面计算最长有效括号的长度
         *       遍历字符串: 遇到 ( , 则加入当前下标到栈中；
         *                 遇到 ) , 先出栈, 再计算栈顶下标与当前下标的长度，此长度即为当前 ) 结尾的最长有效括号的长度
         * https://leetcode.cn/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
         * 时间复杂度 O(n), 空间复杂度 O(n)
         */
//        int ans = 0;
//        std::stack<int> stack;
//        stack.push(-1);
//        for (int i = 0; i < s.length(); ++i) {
//            if (s[i] == '(') {
//                stack.push(i);
//            } else {
//                stack.pop();
//                if (stack.empty()) {
//                    stack.push(i);
//                } else {
//                    ans = std::max(ans, i - stack.top());
//                }
//            }
//        }
//        return ans;

        /*
         * 方法3: 每遇到左括号 left + 1 , 每遇到 右括号 right + 1, 当 left == right 时计算最长有效括号的长度
         *       存在特殊情况, 比如 "((())", 这种情况是无法计算长度的, 解决方法是反过来按照如上方法再计算一遍即可
         * 时间复杂度 O(n), 空间复杂度 O(1)
         */
        int left = 0, right = 0, ans = 0;
        for (auto c: s) {
            c == '(' ? ++left : ++right;
            if (left == right) {
                ans = std::max(ans, right * 2);
            } else if (right > left) {
                left = right = 0;
            }
        }
        if (left > right) {
            left = right = 0;
            for (int i = s.length() - 1; i >= 0; --i) {
                s[i] == ')' ? ++left : ++right;
                if (left == right) {
                    ans = std::max(ans, right * 2);
                } else if (right > left) {
                    left = right = 0;
                }
            }
        }
        return ans;
    }
};

int main() {
    std::cout << Solution().longestValidParentheses("()()((())))") << std::endl;
    std::cout << Solution().longestValidParentheses("(((())") << std::endl;
    std::cout << Solution().longestValidParentheses("())((())") << std::endl;
    std::cout << Solution().longestValidParentheses(")()())") << std::endl;
    std::cout << Solution().longestValidParentheses("") << std::endl;
    std::cout << Solution().longestValidParentheses("()(()") << std::endl;
    std::cout << Solution().longestValidParentheses("(()())") << std::endl;
    return 0;
}