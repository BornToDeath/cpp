//
// Created by lixiaoqing on 2023/1/10.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        /**
         * 方法1：递归（DFS）
         */
//        if (p == nullptr || q == nullptr) {
//            if (p == nullptr && q == nullptr) {
//                return true;
//            }
//            return false;
//        }
//        if (p->val != q->val) {
//            return false;
//        }
//        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        /**
         * 方法2：迭代（BFS）
         */
        std::queue<TreeNode *> q1, q2;
        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty()) {
            auto node1 = q1.front();
            q1.pop();
            auto node2 = q2.front();
            q2.pop();
            if (node1 == nullptr || node2 == nullptr) {
                if (node1 == nullptr && node2 == nullptr) {
                    continue;
                }
                return false;
            } else if (node1->val != node2->val) {
                return false;
            }
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->left);
            q2.push(node2->right);
        }
        if (q1.empty() && q2.empty()) {
            return true;
        }
        return false;
    }
};