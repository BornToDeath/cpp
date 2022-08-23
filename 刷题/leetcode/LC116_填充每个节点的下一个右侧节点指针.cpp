//
// Created by lixiaoqing on 2022/8/23.
//

#include <iostream>
#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        /**
         * 方法1：层次遍历，使用队列记录每一层节点
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        if (root == nullptr) {
//            return nullptr;
//        }
//        std::queue<Node *> queue;
//        queue.push(root);
//        while (!queue.empty()) {
//            Node *last = nullptr;
//            int size = queue.size();
//            for (int i = 0; i < size; ++i) {
//                auto node = queue.front();
//                queue.pop();
//                node->next = last;
//                last = node;
//                if (node->right) {
//                    queue.push(node->right);
//                }
//                if (node->left) {
//                    queue.push(node->left);
//                }
//            }
//        }
//        return root;

        /**
         * 方法2：递归。先处理第 N 层，再利用第 N 层的 next 节点递归处理第 N + 1 层
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        if (root == nullptr) {
//            return root;
//        }
//        auto node = root;
//        while (node) {
//            if (node->left) {
//                node->left->next = node->right;
//                if (node->next) {
//                    node->right->next = node->next->left;
//                }
//            }
//            node = node->next;
//        }
//        connect(root->left);
//        return root;

        /**
         * 方法3：迭代，在方法2的基础上进行优化
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        if (root == nullptr) {
            return root;
        }
        auto leftestNode = root;
        while (leftestNode->left) {
            auto node = leftestNode;
            while (node) {
                if (node->left) {
                    node->left->next = node->right;
                    if (node->next) {
                        node->right->next = node->next->left;
                    }
                }
                node = node->next;
            }
            leftestNode = leftestNode->left;
        }
        return root;
    }

private:
//    Node *pre = nullptr;
};