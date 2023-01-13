//
// Created by lixiaoqing on 2023/1/13.
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
#include <vector>
#include <stack>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        /**
         * 方法1：递归
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        if (root == nullptr) {
//            return {};
//        }
//        postorderTraversal(root->left);
//        postorderTraversal(root->right);
//        nums.emplace_back(root->val);
//        return nums;

        /**
         * 方法2：迭代。按照 根右左 的方式遍历，再对结果进行反转
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        std::vector<int> res;
//        std::stack<TreeNode *> _stack;
//        while (root || !_stack.empty()) {
//            if (root == nullptr) {
//                root = _stack.top();
//                _stack.pop();
//            }
//            res.emplace_back(root->val);
//            if (root->left) {
//                _stack.push(root->left);
//            }
//            root = root->right;
//        }
//        std::reverse(res.begin(), res.end());
//        return res;

        /**
         * 方法3：迭代。模拟栈调用
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        std::vector<int> res;
        std::stack<TreeNode *> _stack;
        TreeNode *prev = nullptr;
        while (root || !_stack.empty()) {
            while (root) {
                _stack.push(root);
                root = root->left;
            }
            root = _stack.top();
            _stack.pop();
            if (root->right == nullptr || root->right == prev) {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                _stack.push(root);
                root = root->right;
            }
        }
        return res;
    }

private:
    std::vector<int> nums;
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    auto res = Solution().postorderTraversal(root);
    for (auto e: res) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
    return 0;
}