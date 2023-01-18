//
// Created by lixiaoqing on 2022/10/27.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        /**
         * 方法：堆排序
         * 时间复杂度 O(nlogk) ，空间复杂度 O(k)
         */
        if (k <= 0) {
            return {};
        }
        if (input.size() <= k) {
            return input;
        }

        std::priority_queue<int> q;
        for (auto e: input) {
            if (q.size() < k) {
                q.push(e);
            } else if (q.top() > e) {
                q.pop();
                q.push(e);
            }
        }

        int n = q.size();
        std::vector<int> ans(n);
        while (!q.empty()) {
            ans[--n] = q.top();
            q.pop();
        }
        return ans;
    }
};

int main() {
    std::vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
    int k = 0;
    auto res = Solution().GetLeastNumbers_Solution(input, k);
    for (auto o: res) {
        std::cout << o << ", ";
    }
    std::cout << std::endl;
    return 0;
}