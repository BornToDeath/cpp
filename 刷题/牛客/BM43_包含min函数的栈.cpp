//
// Created by lixiaoqing on 2022/10/27.
//

#include <stack>

class Solution {
public:
    void push(int value) {
        _stack.push(value);
        if (minStack.empty() || value < minStack.top()) {
            minStack.push(value);
        } else {
            minStack.push(minStack.top());
        }
    }

    void pop() {
        if (!_stack.empty()) {
            _stack.pop();
            minStack.pop();
        }
    }

    int top() {
        return _stack.top();
    }

    int min() {
        if (minStack.empty()) {
            return -1;
        }
        return minStack.top();
    }

private:
    std::stack<int> _stack;
    std::stack<int> minStack;
};