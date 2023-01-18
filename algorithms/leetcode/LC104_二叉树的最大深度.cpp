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

#include <iostream>
#include <queue>
#include "TreeNode.h"

class Solution {
public:
    int maxDepth(TreeNode *root) {
        /**
         * 方法1：递归
         */
//        if (root == nullptr) {
//            return 0;
//        }
//        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));

        /**
         * 方法2：DFS
         */
//        dfs(root, 0);
//        return max;

        /**
         * 方法3：BFS
         */
        return bfs(root);
    }

private:
    void dfs(TreeNode *root, int depth) {
        if (root == nullptr) {
            return;
        }
        ++depth;
        if (depth > max) {
            max = depth;
        }
        dfs(root->left, depth);
        dfs(root->right, depth);
    }

    int bfs(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        std::queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            ++depth;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                auto node = queue.front();
                queue.pop();
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
        }
        return depth;
    }

private:
    int max = 0;
};