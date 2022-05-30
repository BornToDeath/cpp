//
// Created by lixiaoqing on 2022/5/7.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

#include "TreeNode.h"

class Solution {
public:
    /**
     *
     * @param t1 TreeNode类
     * @param t2 TreeNode类
     * @return TreeNode类
     */
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (!(t1 && t2)) {
            return (t1 ? t1 : t2);
        }
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};