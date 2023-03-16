//
// Created by lixiaoqing on 2023/3/16.
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

#include <queue>
#include <vector>
#include "TreeNode.h"

using std::vector;

class Solution {
public:
    vector<int> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<int> ans;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            const int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                ans.emplace_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};