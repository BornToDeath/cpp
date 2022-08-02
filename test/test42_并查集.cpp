//
// Created by lixiaoqing on 2022/8/2.
//

/**
 * 学习并查集。
 * 参考：
 *   1. https://www.cnblogs.com/onlyblues/p/14668087.html
 *   2. https://segmentfault.com/a/1190000004023326
 */

#include <iostream>
#include <vector>


/**
 * 并查集。
 * 此处为了简便起见，构建的并查集始终进行路径压缩，子节点直接指向根节点，所以树的高度始终为2。
 */
class UnionFind {

public:

    void init(int n) {
        parents.resize(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;  // 初始化每个元素的父节点是自身
        }
    }

    // 合并：将 x 所在的集合合并到 y 所在的集合中
    void unoin(int x, int y) {
        auto rootX = find(x);
        auto rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        parents[rootX] = rootY;
    }

    // 查询，带路径压缩
    int find(int x) {
        if (x == parents[x]) {
            return x;
        }
        // 路径压缩
        parents[x] = find(parents[x]);  // 将 x 的父节点置为根节点
        return parents[x];
    }

    // 判断是否联通（即是否属于一个集合）
    bool isConnect(int x, int y) {
        return find(x) == find(y);
    }

    // 计算并查集中不连通的集合个数
    int set_count() {
        int count = 0;
        for (int i = 0; i < parents.size(); ++i) {
            if (i == parents[i]) {
                ++count;
            }
        }
        return count;
    }

private:
    std::vector<int> parents;
};