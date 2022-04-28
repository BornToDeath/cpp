//
// Created by lixiaoqing on 2022/3/16.
//

#include <iostream>
#include <stack>

class Solution {
public:
    void push(int value) {
        _stack.push(value);
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    void pop() {
        if (_stack.top() == minStack.top()) {
            minStack.pop();
        }
        _stack.pop();
    }

    int top() {
        return _stack.top();
    }

    int min() {
        return minStack.top();
    }

private:
    std::stack<int> _stack;
    std::stack<int> minStack;
};

int main() {
    Solution _stack;
    _stack.push(-1);
    _stack.push(2);
    std::cout << _stack.min() << std::endl;
    std::cout << _stack.top() << std::endl;
    _stack.pop();
    _stack.push(1);
    std::cout << _stack.top() << std::endl;
    std::cout << _stack.min() << std::endl;
    return 0;
}