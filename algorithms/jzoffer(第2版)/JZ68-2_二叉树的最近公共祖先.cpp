//
// Created by lixiaoqing on 2023/3/28.
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
        /*
         * 最近公共祖先满足如下条件：
         *   1. 是 p 或者 q
         *   2. 否则，在 root 的左右子树中
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p || root == q) {
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