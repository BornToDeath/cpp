//
// Created by lixiaoqing on 2022/7/7.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        /**
         * 方法1：拓扑排序，逆序遍历（按照入度）
         */
//        // 记录某个节点的入度节点
//        std::vector<std::vector<int>> edges(numCourses);
//        // 记录某个节点出度节点个数
//        std::vector<int> indeg(numCourses);
//
//        for (const auto& info: prerequisites) {
//            edges[info[1]].push_back(info[0]);
//            ++indeg[info[0]];
//        }
//
//        queue<int> q;
//        for (int i = 0; i < numCourses; ++i) {
//            if (indeg[i] == 0) {
//                q.push(i);
//            }
//        }
//
//        int visited = 0;
//        while (!q.empty()) {
//            ++visited;
//            int u = q.front();
//            q.pop();
//            for (int v: edges[u]) {
//                --indeg[v];
//                if (indeg[v] == 0) {
//                    q.push(v);
//                }
//            }
//        }
//
//        return visited == numCourses;

        /**
         * 方法2：拓扑排序，顺序遍历（按照出度）
         */
        // 记录某个节点的入度节点个数
        std::vector<int> indeg(numCourses);
        // 记录某个节点的出度节点
        std::vector<std::vector<int>> edges(numCourses);
        for (auto &pair: prerequisites) {
            ++indeg[pair[1]];
            edges[pair[0]].emplace_back(pair[1]);
        }
        std::queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int visited = 0;
        while (!q.empty()) {
            ++visited;
            auto e = q.front();
            q.pop();
            for (auto n: edges[e]) {
                --indeg[n];
                if (indeg[n] == 0) {
                    q.push(n);
                }
            }
        }
        return visited == numCourses;

        /**
         * 方法3：转化为：判断有向图中是否存在环。
         * 见：https://leetcode.cn/problems/course-schedule/solution/ke-cheng-biao-by-leetcode-solution/
         */
    }
};

int main() {
    int num = 4;
    std::vector<std::vector<int>> nums = {
            {1, 2},
            {3, 2},
            {2, 0}
    };
    std::cout << Solution().canFinish(num, nums) << std::endl;
    return 0;
}