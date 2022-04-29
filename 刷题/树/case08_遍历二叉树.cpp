//
// Created by lixiaoqing on 2022/4/29.
//

#include <iostream>
#include <queue>
#include "TreeNode.h"

void print(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    std::queue<TreeNode *> _queue;
    _queue.push(root);
    while (!_queue.empty()) {
        auto size = _queue.size();
        for (auto i = 0; i < size; ++i) {
            auto node = _queue.front();
            _queue.pop();
            if (node) {
                std::cout << (char) node->val << ", ";
                _queue.push(node->left);
                _queue.push(node->right);
            } else {
                std::cout << "#, ";
            }
        }
        std::cout << std::endl;
    }
}

/**
 * 根据一个先序序列，输出二叉树的中序序列
 */
class Solution {
public:
    void inOrder(const std::string &preOrder) {
        int index = 0;
        auto root = createBinaryTree(preOrder, index);
//        print(root);
        inOrder(root);
    }

private:
    void inOrder(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left);
        std::cout << (char) root->val << ", ";
        inOrder(root->right);
    }

    TreeNode *createBinaryTree(const std::string &preOrder, int &index) {
        if (preOrder[index] == '#') {
            ++index;
            return nullptr;
        }
        auto node = new TreeNode(preOrder[index++]);
        node->left = createBinaryTree(preOrder, index);
        node->right = createBinaryTree(preOrder, index);
        return node;
    }
};

int main() {
    std::string inOrder = "abc##de#g##f###";
    Solution().inOrder(inOrder);
    return 0;
}
