//
// Created by lixiaoqing on 2022/7/7.
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        /**
         * 方法1：递归：DFS
         */
//        if (!root1) {
//            return root2;
//        } else if (!root2) {
//            return root1;
//        }
//        root1->val += root2->val;
//        root1->left = mergeTrees(root1->left, root2->left);
//        root1->right = mergeTrees(root1->right, root2->right);
//        return root1;

        /**
         * 方法2：迭代：BFS
         */
        if (!root1) {
            return root2;
        } else if (!root2) {
            return root1;
        }
        std::queue<TreeNode *> queue1;
        queue1.push(root1);
        std::queue<TreeNode *> queue2;
        queue2.push(root2);
        while (!queue1.empty() && !queue2.empty()) {
            auto node1 = queue1.front();
            queue1.pop();
            auto node2 = queue2.front();
            queue2.pop();
            node1->val += node2->val;
            if (node1->left && node2->left) {
                queue1.push(node1->left);
                queue2.push(node2->left);
            } else if (!node1->left) {
                node1->left = node2->left;
            }
            if (node1->right && node2->right) {
                queue1.push(node1->right);
                queue2.push(node2->right);
            } else if (!node1->right) {
                node1->right = node2->right;
            }
        }
        return root1;
    }
};