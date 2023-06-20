//
// Created by lixiaoqing on 2023/6/20.
//

#include <vector>
#include <string>
#include <stack>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        /*
         * 方法: 借助栈
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
        std::stack<int> s;
        for (const auto &t: tokens) {
            if (t == "+") {
                auto n = s.top();
                s.pop();
                s.top() += n;
            } else if (t == "-") {
                auto n = s.top();
                s.pop();
                s.top() -= n;
            } else if (t == "*") {
                auto n = s.top();
                s.pop();
                s.top() *= n;
            } else if (t == "/") {
                auto n = s.top();
                s.pop();
                s.top() /= n;
            } else {
                s.push(std::stoi(t));
            }
        }
        return s.top();
    }
};

int main() {
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    tokens = {"4", "13", "5", "/", "+"};
    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::cout << Solution().evalRPN(tokens) << std::endl;
    return 0;
}