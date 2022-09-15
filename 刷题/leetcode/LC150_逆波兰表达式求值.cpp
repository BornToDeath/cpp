//
// Created by lixiaoqing on 2022/9/15.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        std::stack<long> nums;
        for (auto &s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                auto num = nums.top();
                nums.pop();
                switch (s[0]) {
                    case '+':
                        nums.top() = nums.top() + num;
                        break;
                    case '-':
                        nums.top() = nums.top() - num;
                        break;
                    case '*':
                        nums.top() = nums.top() * num;
                        break;
                    case '/':
                        nums.top() = nums.top() / num;
                        break;
                }
            } else {
                nums.push(std::stoi(s));
            }
        }
        return nums.top();
    }
};