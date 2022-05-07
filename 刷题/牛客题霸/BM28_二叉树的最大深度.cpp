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

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型
     */
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};