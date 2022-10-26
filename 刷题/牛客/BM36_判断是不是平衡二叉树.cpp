//
// Created by lixiaoqing on 2022/10/26.
//

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    bool IsBalanced_Solution(TreeNode *pRoot) {
        if (pRoot == nullptr) {
            return true;
        }
        isBalancedTree(pRoot);
        return isBalanced;
    }

private:
    int isBalancedTree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        auto leftHeight = isBalancedTree(root->left);
        if (!isBalanced) {
            return false;
        }
        auto rightHeight = isBalancedTree(root->right);
        if (!isBalanced) {
            return false;
        }
        isBalanced = std::abs(leftHeight - rightHeight) < 2;
        return std::max(leftHeight, rightHeight) + 1;
    }

private:
    bool isBalanced{true};
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(44);
    root->left->left->left->left = new TreeNode(45);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    std::cout << Solution().IsBalanced_Solution(root) << std::endl;
    return 0;
}