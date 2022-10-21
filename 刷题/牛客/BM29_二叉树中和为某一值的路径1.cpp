//
// Created by lixiaoqing on 2022/10/21.
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
     * @param root TreeNode类
     * @param sum int整型
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode *root, int sum) {
        /**
         * 方法：递归
         * 时间复杂度 O(n) ，空间复杂度 O(树的高度)
         */
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == sum;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};