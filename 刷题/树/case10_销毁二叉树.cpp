//
// Created by lixiaoqing on 2022/4/29.
//

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    void distroyBinaryTree(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        distroyBinaryTree(root->left);
        distroyBinaryTree(root->right);
        std::cout << "释放结点: " << root->val << std::endl;
        delete root;
    }
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(5);
    Solution().distroyBinaryTree(root);
    return 0;
}