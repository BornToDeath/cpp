//
// Created by lixiaoqing on 2022/6/29.
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

#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> ans;
        std::queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            ans.push_back(std::vector<int>());
            int count = queue.size();
            for (int i = 0; i < count; ++i) {
                auto node = queue.front();
                queue.pop();
                ans.back().emplace_back(node->val);
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
        }
        return ans;
    }
};