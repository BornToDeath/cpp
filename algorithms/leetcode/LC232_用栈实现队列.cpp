//
// Created by lixiaoqing on 2023/1/18.
//

#include <stack>

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            adjust();
        }
        auto o = s2.top();
        s2.pop();
        return o;
    }

    int peek() {
        if (s2.empty()) {
            adjust();
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    void adjust() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

private:
    std::stack<int> s1;  // 输入栈
    std::stack<int> s2;  // 输出栈
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */