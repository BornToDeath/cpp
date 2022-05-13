//
// Created by lixiaoqing on 2022/5/12.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        std::stack<int> nums;
        int num = 0;
        char op = '+';
        for (auto i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                num = num * 10 + (ch - '0');
                if (i != s.length() - 1) {
                    continue;
                }
            }
            if (ch == '(') {
                int end = i;
                int count = 1;
                while (count > 0) {
                    ++end;
                    if (s[end] == '(') {
                        ++count;
                    } else if (s[end] == ')') {
                        --count;
                    }
                }
                // 将括号内的表达式递归求值
                num = solve(s.substr(i + 1, end - i - 1));
                i = end;
                if (i != s.length() - 1) {
                    continue;
                }
            }
            switch (op) {
                case '+':
                    break;
                case '-':
                    num *= -1;
                    break;
                case '*':
                    num *= nums.top();
                    nums.pop();
                    break;
                default:
                    throw "Unexpected Operator!";
            }
            nums.push(num);
            num = 0;
            op = ch;
        }
        int sum = 0;
        while (!nums.empty()) {
            sum += nums.top();
            nums.pop();
        }
        return sum;
    }
};

int main() {
    std::string str = "(2*(3-4))*5";
    std::cout << Solution().solve(str) << std::endl;
    return 0;
}