//
// Created by lixiaoqing on 2023/3/8.
//

#include <stack>

class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) {
            return -1;
        }
        auto num = s2.top();
        s2.pop();
        return num;
    }

private:
    std::stack<int> s1;  // 输入栈
    std::stack<int> s2;  // 输出栈
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */