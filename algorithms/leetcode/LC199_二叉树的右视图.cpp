//
// Created by lixiaoqing on 2023/7/24.
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
    vector<int> rightSideView(TreeNode *root) {
        /*
         * 方法: 层次遍历(BFS)
         * 时间复杂度 O(n), 空间复杂度 O(n)
         */
        if (root == nullptr) {
            return {};
        }
        std::vector<int> ans;
        std::queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            const int size = nodes.size();
            for (int i = 0; i < size; ++i) {
                auto node = nodes.front();
                nodes.pop();
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
                if (i == size - 1) {
                    ans.push_back(node->val);
                }
            }
        }
        return ans;
    }
};