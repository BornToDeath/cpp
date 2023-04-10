//
// Created by lixiaoqing on 2023/3/23.
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
#include "TreeNode.h"

class Solution {
public:
    int maxDepth(TreeNode *root) {
        /*
         * 方法1：递归
         * 时间复杂度 O(n) ，空间复杂度 O(logn)
         */
//        if (root == nullptr) {
//            return 0;
//        }
//        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;

        /*
         * 方法2：层次遍历
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        if (root == nullptr) {
            return 0;
        }
        int depth = 0;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            ++depth;
            auto size = q.size();
            while (size > 0) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                --size;
            }
        }
        return depth;
    }
};