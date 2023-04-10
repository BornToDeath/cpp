//
// Created by lixiaoqing on 2023/3/15.
//

#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        _stack.push(x);
        if (_minStack.empty() || x <= _minStack.top()) {
            _minStack.push(x);
        }
    }

    void pop() {
        if (_stack.empty()) {
            throw "stack is empty";
        }
        if (_stack.top() == _minStack.top()) {
            _minStack.pop();
        }
        _stack.pop();
    }

    int top() {
        if (_stack.empty()) {
            throw "stack is empty";
        }
        return _stack.top();
    }

    int min() {
        if (_minStack.empty()) {
            throw "stack is empty";
        }
        return _minStack.top();
    }

private:
    std::stack<int> _stack, _minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */