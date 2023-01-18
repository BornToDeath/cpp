//
// Created by lixiaoqing on 2022/4/28.
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
                std::cout << node->val << ", ";
                _queue.push(node->left);
                _queue.push(node->right);
            } else {
                std::cout << "#, ";
            }
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    void flipBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        auto temp = root->left;
        root->left = root->right;
        root->right = temp;
        flipBinaryTree(root->left);
        flipBinaryTree(root->right);
    }
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(5);
    print(root);
    std::cout << "-----------------" << std::endl;

    Solution().flipBinaryTree(root);
    print(root);
    return 0;
}