//
// Created by lixiaoqing on 2023/4/10.
//

#include <iostream>
#include <queue>
#include <stack>
#include <deque>

/*
 * 方法: 借助一个双端队列 std::deque
 */
class MaxQueue {
public:
    MaxQueue() {

    }

    int max_value() {
        return d.empty() ? -1 : d.front();
    }

    void push_back(int value) {
        q.push(value);
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
    }

    int pop_front() {
        if (q.empty()) {
            return -1;
        }
        auto n = q.front();
        q.pop();
        if (n == d.front()) {
            d.pop_front();
        }
        return n;
    }

private:
    std::queue<int> q;  // 存储实际的元素
    std::deque<int> d;  // 存储最大值, 保证递减(非严格)
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */


int main() {
    MaxQueue q;

    q.push_back(1);
    std::cout << q.max_value() << ", ";

    q.push_back(2);
    std::cout << q.max_value() << ", ";

    q.push_back(3);
    std::cout << q.max_value() << ", ";

    q.push_back(2);
    std::cout << q.max_value() << ", ";

    q.pop_front();
    std::cout << q.max_value() << ", ";

    q.pop_front();
    std::cout << q.max_value() << ", ";

    q.pop_front();
    std::cout << q.max_value() << ", ";

    q.pop_front();
    std::cout << q.max_value() << ", ";

    q.pop_front();
    std::cout << q.max_value() << ", ";

    return 0;
}