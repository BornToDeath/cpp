//
// Created by lixiaoqing on 2022/7/21.
//

#include <iostream>

/**
 * 线段树。
 * 注意：此线段树的作用是计算区间和，如果想要计算区间最大值，需要对程序进行调整
 */
class SegmentTree {

private:

    // 线段树节点数据结构。注意，该数据结构中没有记录当前节点所表示的区间范围
    class Node {
    public:
        Node *left{nullptr};   // 左孩子节点
        Node *right{nullptr};  // 右孩子节点
        int val{0};            // 记录区间和
        int lazy{0};           // 懒惰标记
    };

public:

    SegmentTree() : root(new Node()) {

    }

    // 计算 [l, r] 区间和
    int query(int l, int r) {
        return query(root, 0, N, l, r);
    }

    // 将 [l, r] 区间每个元素加上 val
    void update(int l, int r, int val) {
        update(root, 0, N, l, r, val);
    }


private:

    int query(Node *node, int start, int end, int l, int r) {
        // 当前区间包含在目标区间中
        if (l <= start && r >= end) {
            return node->val;
        }
        int ans = 0;
        auto mid = (end - start) / 2 + start;
        pushDown(node, mid - start + 1, end - mid);
        // 左边部分有交集
        if (l <= mid) {
            ans += query(node->left, start, mid, l, r);
        }
        // 右边部分有交集
        if (r > mid) {
            ans += query(node->right, mid + 1, end, l, r);
        }
        return ans;
    }

    // 线段树更新
    void update(Node *node, int start, int end, int l, int r, int val) {
        if (l <= start && r >= end) {
            node->val += (end - start + 1) * val;
            node->lazy += val;
            return;
        }
        auto mid = (end - start) / 2 + start;
        pushDown(node, mid - start + 1, end - mid);
        if (l <= mid) {
            update(node->left, start, mid, l, r, val);
        }
        if (r > mid) {
            update(node->right, mid + 1, end, l, r, val);
        }
        pushUp(node);
    }

private:

    // 向下更新懒惰标记
    void pushDown(Node *node, int leftNum, int rightNum) {
        if (node->left == nullptr) {
            node->left = new Node();
        }
        if (node->right == nullptr) {
            node->right = new Node();
        }
        if (node->lazy == 0) {
            return;
        }
        // 更新左右孩子的区间和
        node->left->val += node->lazy * leftNum;
        node->right->val += node->lazy * rightNum;
        // 向下传递懒惰值
        node->left->lazy += node->lazy;
        node->right->lazy += node->lazy;
        // 更新之后将当前懒惰值置为0
        node->lazy = 0;
    }

    // 向上更新区间和
    void pushUp(Node *node) {
        node->val = node->left->val + node->right->val;
    }

private:
    // 线段树根节点
    Node *root{nullptr};
    // 线段树最大值，也即区间范围
    const int N = 1e9;
};

int main() {
    SegmentTree tree;
    tree.update(0, 4, 10);
    tree.update(0, 3, 10);
    std::cout << tree.query(0, 4) << std::endl;
    return 0;
}



