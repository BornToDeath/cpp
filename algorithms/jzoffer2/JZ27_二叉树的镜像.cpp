//
// Created by lixiaoqing on 2023/3/14.
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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto node = mirrorTree(root->left);
        root->left = mirrorTree(root->right);
        root->right = node;
        return root;
    }
};