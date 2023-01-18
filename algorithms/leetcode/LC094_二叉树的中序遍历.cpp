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

#include <vector>
#include <stack>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        /**
         * 方法1：递归
         */
//        std::vector<int> v;
//        inorder(root, v);
//        return v;

        /**
         * 方法2：迭代
         */
        std::vector<int> v;
        std::stack<TreeNode *> stack;
        while (root || !stack.empty()) {
            while (root) {
                stack.push(root);
                root = root->left;
            }
            v.emplace_back(stack.top()->val);
            root = stack.top()->right;
            stack.pop();
        }
        return v;
    }

private:
    void inorder(TreeNode *root, std::vector<int> &v) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, v);
        v.emplace_back(root->val);
        inorder(root->right, v);
    }

};