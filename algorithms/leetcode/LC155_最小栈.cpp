//
// Created by lixiaoqing on 2022/6/21.
//

#include <stack>

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        stack.push(val);
        if (!minStack.empty() && val > minStack.top()) {
            minStack.push(minStack.top());
        } else {
            minStack.push(val);
        }
    }

    void pop() {
        if (stack.empty()) {
            throw "stack is empty.";
        }
        stack.pop();
        minStack.pop();
    }

    int top() {
        if (stack.empty()) {
            throw "stack is empty.";
        }
        return stack.top();
    }

    int getMin() {
        if (minStack.empty()) {
            throw "stack is empty.";
        }
        return minStack.top();
    }

private:
    std::stack<int> stack;
    std::stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */