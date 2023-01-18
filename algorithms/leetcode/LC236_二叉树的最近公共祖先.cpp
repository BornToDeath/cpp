//
// Created by lixiaoqing on 2022/7/14.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "TreeNode.h"

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        /**
         * 最近公共祖先具有如下特征：
         * 1. 如果 p 或 q 是公共祖先，则另一节点一定在 p/q 的左/右子树中；
         * 2. 否则，q 或 q 分别在公共祖先的左右子树中。
         */
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        return root;
    }
};