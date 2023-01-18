//
// Created by lixiaoqing on 2022/11/21.
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

#include "TreeNode.h"
#include <stack>
#include <iostream>

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        /**
         * 方法1：中序遍历，递归写法
         */
//        if (root == nullptr) {
//            return -1;
//        }
//        int res = -1;
//        if (root->left && (res = kthSmallest(root->left, k)) != -1) {
//            return res;
//        }
//        ++count;
//        if (count == k) {
//            res = root->val;
//        } else if (root->right) {
//            res = kthSmallest(root->right, k);
//        }
//        return res;

        /**
         * 方法2：中序遍历，迭代写法
         */
        if (root == nullptr) {
            return -1;
        }
        std::stack<TreeNode *> _stack;
        while (root != nullptr || !_stack.empty()) {
            while (root) {
                _stack.push(root);
                root = root->left;
            }
            root = _stack.top();
            _stack.pop();
            if (--k == 0) {
                return root->val;
            }
            root = root->right;
        }
        return -1;
    }

private:
    // 记录已经访问过的节点个数
    int count = 0;
};

int main() {
    auto root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);

    std::cout << Solution().kthSmallest(root, 1) << std::endl;
    std::cout << Solution().kthSmallest(root, 2) << std::endl;
    std::cout << Solution().kthSmallest(root, 3) << std::endl;
    std::cout << Solution().kthSmallest(root, 6) << std::endl;
    std::cout << Solution().kthSmallest(root, 7) << std::endl;

    return 0;
}