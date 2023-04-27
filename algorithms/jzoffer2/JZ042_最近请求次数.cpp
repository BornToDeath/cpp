//
// Created by lixiaoqing on 2023/4/27.
//

#include <queue>

class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        while (!q.empty() && q.front() + 3000 < t) {
            q.pop();
        }
        q.emplace(t);
        return q.size();
    }

private:
    std::queue<int> q;
};