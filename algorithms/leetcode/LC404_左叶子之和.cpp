//
// Created by lixiaoqing on 2023/2/2.
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
    int sumOfLeftLeaves(TreeNode *root) {
        /**
         * 方法1：DFS（递归）
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        if (root == nullptr) {
//            return 0;
//        }
//        int sum = 0;
//        if (root->left) {
//            if (root->left->left == nullptr && root->left->right == nullptr) {
//                sum += root->left->val;
//            } else {
//                sum += sumOfLeftLeaves(root->left);
//            }
//        }
//        sum += sumOfLeftLeaves(root->right);
//        return sum;

        /**
         * 方法2：BFS（迭代）
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            const int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    if (node->left->left == nullptr && node->left->right == nullptr) {
                        sum += node->left->val;
                    } else {
                        q.push(node->left);
                    }
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return sum;
    }
};