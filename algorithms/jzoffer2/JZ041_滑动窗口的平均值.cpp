//
// Created by lixiaoqing on 2023/4/27.
//

#include <queue>

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : capacity(size) {

    }

    double next(int val) {
        sum += val;
        q.emplace(val);
        if (q.size() > capacity) {
            sum -= q.front();
            q.pop();
        }
        return sum * 1.0 / q.size();
    }

private:
    std::queue<int> q;
    int sum{0};
    const int capacity{0};
};