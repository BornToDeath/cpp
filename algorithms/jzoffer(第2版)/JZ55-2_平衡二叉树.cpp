//
// Created by lixiaoqing on 2023/3/23.
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

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return dfs(root) != -1;
    }

private:
    int dfs(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        auto leftDepth = dfs(root->left);
        if (leftDepth == -1) {
            return -1;
        }
        auto rightDepth = dfs(root->right);
        if (rightDepth == -1) {
            return -1;
        }
        return abs(leftDepth - rightDepth) > 1 ? -1 : std::max(leftDepth, rightDepth) + 1;
    }
};