//
// Created by lixiaoqing on 2022/4/28.
//

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    /**
     * 判断一颗二叉树是否是单值二叉树
     * @param root
     * @return
     */
    bool isUnivalTree(TreeNode *root) {
        /**
         * 方法1：递归判断所有结点的值是否相同
         */
//        if (root == nullptr) {
//            return true;
//        }
//        return isUnivalTree(root, root->val);

        /**
         * 方法2：如果是单值二叉树，则父结点与孩子结点的值都相同
         */
        if (root == nullptr) {
            return true;
        }
        if ((root->left && root->left->val != root->val) || (root->right && root->right->val != root->val)) {
            return false;
        }
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }

private:
    bool isUnivalTree(TreeNode *root, int val) {
        if (root == nullptr) {
            return true;
        }
        if (root->val != val) {
            return false;
        }
        return isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
    }
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);

    std::cout << std::boolalpha;
    std::cout << Solution().isUnivalTree(root) << std::endl;
    return 0;
}