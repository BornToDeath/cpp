//
// Created by lixiaoqing on 2022/6/30.
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

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        depth(root);
        return delimiter;
    }

private:
    int depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        auto left = depth(root->left);
        auto right = depth(root->right);
        delimiter = std::max(left + right, delimiter);
        return 1 + std::max(left, right);
    }

private:
    int delimiter = 0;
};