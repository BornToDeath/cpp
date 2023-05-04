//
// Created by lixiaoqing on 2023/5/4.
//

#include <vector>
#include <queue>

using std::vector;

class KthLargest {
public:
    KthLargest(int k, vector<int> &nums) : k(k) {
        for (auto n: nums) {
            add(n);
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int k;
};