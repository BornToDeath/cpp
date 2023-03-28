//
// Created by lixiaoqing on 2023/3/27.
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
         * 方法1：递归
         * 时间复杂度 O(n) , (最坏情况下) 空间复杂度 O(n)
         */
//        if (root == nullptr) {
//            return nullptr;
//        }
//        if (root->val > p->val && root->val > q->val) {
//            return lowestCommonAncestor(root->left, p, q);
//        } else if (root->val < p->val && root->val < q->val) {
//            return lowestCommonAncestor(root->right, p, q);
//        } else {
//            return root;
//        }

        /*
         * 方法2: 迭代
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        auto ancestor = root;
        while (ancestor) {
            if (ancestor->val > p->val && ancestor->val > q->val) {
                ancestor = ancestor->left;
            } else if (ancestor->val < p->val && ancestor->val < q->val) {
                ancestor = ancestor->right;
            } else {
                break;
            }
        }
        return ancestor;
    }
};