//
// Created by lixiaoqing on 2022/8/1.
//

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

/**
 * 并查集
 */
class UnionFind {
public:
    UnionFind(int n) {
        parents.resize(n);
        weights.resize(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;    // 初始化父节点为自身
            weights[i] = 1.0;  // 初始化权值为1
        }
    }

    // 查找父节点
    int find(int x) {
        if (x == parents[x]) {
            return x;
        }
        // 路径压缩
        auto origin = parents[x];
        parents[x] = find(origin);
        weights[x] *= weights[origin];
        return parents[x];
    }

    // 将 x 所在集合合并到 y 所在集合中。ratio = x / y
    void myunion(int x, int y, double ratio) {
        auto rootX = find(x);
        auto rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        // 令 x 的根节点指向 y 的根节点
        parents[rootX] = rootY;
        // x 的根节点的权值为 = x/y的值 * y到根节点的权值 / x到根节点的权值
        weights[rootX] = ratio * weights[y] / weights[x];
    }

    // 判断 x 和 y 是否在一个并查集内，如果在的话，说明是同根，权值直接相除即可
    double isConnected(int x, int y) {
        if (find(x) != find(y)) {
            return -1;
        }
        return weights[x] / weights[y];
    }

private:
    std::vector<int> parents;     // 存放父节点
    std::vector<double> weights;  // 指向父节点的权值
};

class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        /**
         * 方法1：广度优先搜索。不AC，时间复杂度超限
         */
//        // 统计有多少个变量
//        int nvars = 0;
//        std::unordered_map<std::string, int> vars;
//        for (auto &ele: equations) {
//            if (vars.count(ele[0]) == 0) {
//                vars[ele[0]] = nvars++;
//            }
//            if (vars.count(ele[1]) == 0) {
//                vars[ele[1]] = nvars++;
//            }
//        }
//        // 统计每个节点的连接节点以及权值
//        std::vector<std::vector<std::pair<int, double>>> edges(nvars);
//        for (int i = 0; i < equations.size(); ++i) {
//            edges[vars[equations[i][0]]].push_back({vars[equations[i][1]], values[i]});
//            edges[vars[equations[i][1]]].push_back({vars[equations[i][0]], 1.0 / values[i]});
//        }
//        std::vector<double> ans(queries.size(), -1);
//        for (int i = 0; i < queries.size(); ++i) {
//            auto x = queries[i][0], y = queries[i][1];
//            if (vars.count(x) == 0 || vars.count(y) == 0) {
//                continue;
//            }
//            if (x == y) {
//                ans[i] = 1;
//                continue;
//            }
//            // 对于每个节点，分别计算与其相连的所有节点的权值
//            std::vector<double> ratios(nvars, -1);
//            ratios[vars[x]] = 1;  // 初始化该节点的值为1
//            std::queue<int> queue;
//            queue.push(vars[x]);
//            while (!queue.empty() && ratios[vars[y]] == -1) {
//                auto num = queue.front();
//                queue.pop();
//                // 分别计算每个相邻节点的值
//                for (auto &items: edges[num]) {
//                    ratios[items.first] = ratios[num] * items.second;
//                    queue.push(items.first);
//                }
//            }
//            ans[i] = ratios[vars[y]];
//        }
//        return ans;

        /**
         * 方法2：Floyed 算法
         */
//        // 统计有多少个节点
//        int nvars = 0;
//        std::unordered_map<std::string, int> vars;
//        for (auto &ele: equations) {
//            if (vars.count(ele[0]) == 0) {
//                vars[ele[0]] = nvars++;
//            }
//            if (vars.count(ele[1]) == 0) {
//                vars[ele[1]] = nvars++;
//            }
//        }
//        std::vector<std::vector<double>> graph(nvars, std::vector<double>(nvars, -1));
//        for (int i = 0; i < values.size(); ++i) {
//            int x = vars[equations[i][0]], y = vars[equations[i][1]];
//            graph[x][y] = values[i];
//            graph[y][x] = 1.0 / values[i];
//        }
//        for (int i = 0; i < nvars; ++i) {
//            for (int j = 0; j < nvars; ++j) {
//                for (int k = 0; k < nvars; ++k) {
//                    if (graph[j][i] > 0 && graph[i][k] > 0) {
//                        graph[j][k] = graph[j][i] * graph[i][k];
//                    }
//                }
//            }
//        }
//        std::vector<double> ans(queries.size(), -1);
//        for (int i = 0; i < queries.size(); ++i) {
//            auto x = queries[i][0], y = queries[i][1];
//            if (vars.count(x) == 0 || vars.count(y) == 0) {
//                continue;
//            }
//            if (x == y) {
//                ans[i] = 1;
//            } else {
//                ans[i] = graph[vars[x]][vars[y]];
//            }
//        }
//        return ans;

        /**
         * 方法3：并查集
         */
        int size = equations.size();
        UnionFind unionFind(size * 2);

        // 1. 并查集初始化
        int nvars = 0;
        std::unordered_map<std::string, int> vars;
        for (int i = 0; i < size; ++i) {
            auto &ele = equations[i];
            if (vars.count(ele[0]) == 0) {
                vars[ele[0]] = nvars++;
            }
            if (vars.count(ele[1]) == 0) {
                vars[ele[1]] = nvars++;
            }
            unionFind.myunion(vars[ele[0]], vars[ele[1]], values[i]);
        }

        // 2. 做查询
        std::vector<double> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            auto x = queries[i][0], y = queries[i][1];
            if (vars.count(x) == 0 || vars.count(y) == 0) {
                continue;
            }
            if (x == y) {
                ans[i] = 1;
                continue;
            }
            ans[i] = unionFind.isConnected(vars[x], vars[y]);
        }
        return ans;
    }
};

int main() {
    std::vector<std::vector<std::string>> equations = {{"a", "b"},
                                                       {"e", "f"},
                                                       {"b", "e"}};
    std::vector<double> values = {3.4, 1.4, 2.3};
    std::vector<std::vector<std::string>> queries = {{"b",  "a"},
                                                     {"a",  "f"},
                                                     {"f",  "f"},
                                                     {"e",  "e"},
                                                     {"c",  "c"},
                                                     {"a",  "c"},
                                                     {"f",  "e"},
                                                     {"gg", "gg"}
    };
    auto ans = Solution().calcEquation(equations, values, queries);
    for (auto num: ans) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}