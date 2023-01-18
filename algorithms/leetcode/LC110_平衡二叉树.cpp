//
// Created by lixiaoqing on 2023/1/11.
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
    bool isBalanced(TreeNode *root) {
        return height(root) != -1;
    }

private:
    int height(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        auto left = height(root->left);
        if (left == -1) {
            return -1;
        }
        auto right = height(root->right);
        if (right == -1) {
            return -1;
        }
        if (std::abs(left - right) > 1) {
            return -1;
        }
        return std::max(left, right) + 1;
    }
};

int main() {
    return 0;
}