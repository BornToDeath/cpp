//
// Created by lixiaoqing on 2022/4/28.
//

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        /**
         * 方法1：递归
         */
        if (root == nullptr) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr || root2 == nullptr) {
            if (root1 == nullptr && root2 == nullptr) {
                return true;
            }
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(4);

    std::cout << std::boolalpha;
    std::cout << Solution().isSymmetric(root) << std::endl;
    return 0;
}

