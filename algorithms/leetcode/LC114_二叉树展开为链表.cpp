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


class Solution {
public:
    void flatten(TreeNode *root) {
        /**
         * 方法1：先进行先序遍历，然后再展开
         */
//        if (root == nullptr) {
//            return;
//        }
//        std::vector<TreeNode *> nums;
//        preOrder(root, nums);
//        for (int i = 0; i < nums.size() - 1; ++i) {
//            nums[i]->right = nums[i + 1];
//            nums[i]->left = nullptr;
//        }

        /**
         * 方法2：迭代，借助栈
         */
//        if (root == nullptr) {
//            return;
//        }
//        std::stack<TreeNode*> stack;
//        stack.push(root);
//        TreeNode* pre = nullptr;
//        while (!stack.empty()) {
//            auto node = stack.top();
//            stack.pop();
//            if (pre) {
//                pre->right = node;
//                pre->left = nullptr;
//            }
//            if (node->right) {
//                stack.push(node->right);
//            }
//            if (node->left) {
//                stack.push(node->left);
//            }
//            pre = node;
//        }

        /**
         * 方法3：寻找当前节点的前驱节点。空间复杂度O(1)
         */
        while (root) {
            if (root->left) {
                auto pre = root->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }

private:
    void preOrder(TreeNode *root, std::vector<TreeNode *> &nums) {
        if (root == nullptr) {
            return;
        }
        nums.emplace_back(root);
        preOrder(root->left, nums);
        preOrder(root->right, nums);
    }
};