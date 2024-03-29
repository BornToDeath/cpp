//
// Created by boss on 2023/11/20.
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

#include <queue>
#include "TreeNode.h"

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            const int size = q.size();
            count += size;
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return count;
    }
};