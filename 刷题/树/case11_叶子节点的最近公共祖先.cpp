//
// Created by lixiaoqing on 2022/8/1.
//

/**
 * 这道题是 20220725 字节飞书客户端二面算法题
 */

#include <iostream>
#include <unordered_set>

class Node {
public:
    Node(int val) : val(val), left(nullptr), right(right), parent(nullptr) {

    }

public:
    int val;
    Node *left, *right, *parent;
};

/**
 * 获取两个叶子节点的最近公共祖先，叶子节点具有指向父节点的指针
 * LCA: Lowest Common Ancestor
 * @param node1
 * @param node2
 */
Node *LCA(Node *node1, Node *node2) {
    /**
     * 方法1：两个栈，分别记录两个叶子节点到根节点的路径上的结点，然后从栈顶开始比较，最后一个相等的节点就是 LCA
     */

    /**
     * 方法2：先计算两个叶子节点的高度，然后让较深的节点先向上若干层直至两者处于同一高度，然后两者再同时向上，第一个相等的节点就是 LCA
     */

    /**
     * 方法3：一个 set 记录某个叶子节点从叶子至根的全部节点，然后另一个叶子节点自底向上遍历，第一个在 map 中存在的节点就是 LCA
     */
    std::unordered_set<Node *> nodes;
    while (node1) {
        nodes.emplace(node1);
        node1 = node1->parent;
    }
    while (node2) {
        if (nodes.count(node2) > 0) {
            return node2;
        }
        node2 = node2->parent;
    }
    return nullptr;
}

int main() {
    return 0;
}