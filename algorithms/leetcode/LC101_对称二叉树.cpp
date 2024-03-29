//
// Created by lixiaoqing on 2022/6/16.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "TreeNode.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode *root1, TreeNode *root2) {
        if (!root1 || !root2) {
            if (!root1 && !root2) {
                return true;
            }
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
};