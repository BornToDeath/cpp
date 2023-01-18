//
// Created by lixiaoqing on 2022/5/30.
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
     * @param p TreeNode类
     * @param q TreeNode类
     * @return bool布尔型
     */
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr || q == nullptr || p->val != q->val) {
            if (p == nullptr && q == nullptr) {
                return true;
            }
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};