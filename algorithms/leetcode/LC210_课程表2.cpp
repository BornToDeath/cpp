//
// Created by lixiaoqing on 2022/9/27.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        /**
         * 方法：拓扑排序（广度优先搜索）
         * 时间复杂度 O(m + n) ，空间复杂度 O(m + n)
         */
        // 记录某个节点的入度节点个数
        std::vector<int> indeg(numCourses);
        // 记录某个节点的所有出度节点
        std::vector<std::vector<int>> edges(numCourses, std::vector<int>());
        for (auto &pair: prerequisites) {
            ++indeg[pair[0]];
            edges[pair[1]].push_back(pair[0]);
        }
        // 记录所有入度为0的节点
        std::queue<int> _queue;
        for (int i = 0; i < indeg.size(); ++i) {
            if (indeg[i] == 0) {
                _queue.push(i);
            }
        }
        // 记录处理的入度为0的节点个数
        std::vector<int> ans;
        while (!_queue.empty()) {
            auto val = _queue.front();
            _queue.pop();
            ans.push_back(val);
            for (auto e: edges[val]) {
                --indeg[e];
                if (indeg[e] == 0) {
                    _queue.push(e);
                }
            }
        }
        if (ans.size() != numCourses) {
            return {};
        }
        return ans;
    }
};

int main() {
    int num = 4;
    std::vector<std::vector<int>> courses = {
            {1, 0},
            {2, 0},
            {3, 1},
            {3, 2}
    };
//    int num = 2;
//    std::vector<std::vector<int>> courses = {};
    auto ans = Solution().findOrder(num, courses);
    for (auto e: ans) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
    return 0;
}
