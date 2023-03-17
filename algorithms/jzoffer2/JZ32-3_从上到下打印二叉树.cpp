//
// Created by lixiaoqing on 2023/3/17.
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

#include <vector>
#include "TreeNode.h"
using std::vector;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> ans;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto size = q.size();
            ans.push_back(std::vector<int>(size));
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                ans.back()[i] = node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (ans.size() % 2 == 0) {
                std::reverse(ans.back().begin(), ans.back().end());
            }
        }
        return ans;
    }
};