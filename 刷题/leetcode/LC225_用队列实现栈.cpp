//
// Created by lixiaoqing on 2023/1/17.
//

#include <queue>
#include <iostream>

/**
 * 方法1：两个队列实现栈
 * 时间复杂度 O(n) ，空间复杂度 O(n)
 */
class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        std::swap(q1, q2);
    }

    int pop() {
        auto o = q1.front();
        q1.pop();
        return o;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }

private:
    std::queue<int> q1;  // 存储栈内元素
    std::queue<int> q2;  // 辅助栈
};

/**
 * 方法2：一个队列实现栈
 * 时间复杂度 O(n) ，空间复杂度 O(n)
 */
class MyStack2 {
public:
    MyStack2() {

    }

    void push(int x) {
        auto size = _queue.size();
        _queue.push(x);
        for (int i = 0; i < size; ++i) {
            _queue.push(_queue.front());
            _queue.pop();
        }
    }

    int pop() {
        auto o = _queue.front();
        _queue.pop();
        return o;
    }

    int top() {
        return _queue.front();
    }

    bool empty() {
        return _queue.empty();
    }

private:
    std::queue<int> _queue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    MyStack _stack;
    _stack.push(1);
    _stack.push(2);
    std::cout << _stack.top() << std::endl;
    std::cout << _stack.pop() << std::endl;
    std::cout << _stack.empty() << std::endl;
    return 0;
}