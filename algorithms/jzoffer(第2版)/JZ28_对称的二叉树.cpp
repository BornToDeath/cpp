//
// Created by lixiaoqing on 2023/3/14.
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

#include <stack>
#include "TreeNode.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        /**
         * 方法1：递归
         * 时间复杂度 O(n) ，空间复杂度 O(H) ，其中 H 为树的高度，最差为 O(n)
         */
//        return isSymmetric(root, root);

        /**
         * 方法2：迭代
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        std::stack<TreeNode *> _stack;
        _stack.push(root);
        _stack.push(root);
        while (!_stack.empty()) {
            auto node1 = _stack.top();
            _stack.pop();
            auto node2 = _stack.top();
            _stack.pop();
            if (node1 == nullptr || node2 == nullptr) {
                if (node1 == nullptr && node2 == nullptr) {
                    continue;
                }
                return false;
            }
            if (node1->val != node2->val) {
                return false;
            }
            // 成组入栈
            _stack.push(node1->left);
            _stack.push(node2->right);

            _stack.push(node1->right);
            _stack.push(node2->left);
        }
        return true;
    }

private:
    bool isSymmetric(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) {
            if (root1 == nullptr && root2 == nullptr) {
                return true;
            }
            return false;
        }
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
};