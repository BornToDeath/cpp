//
// Created by lixiaoqing on 2021/10/29.
//

#include <iostream>
#include <stack>
#include "TreeNode.h"


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode *pRoot) {
        /**
         * 方法1：递归
         */
//        return isSymmetricalReal(pRoot, pRoot);

        /**
         * 方法2：迭代
         * 用栈来保存每层的数据。
         */
        if (pRoot == nullptr) {
            return true;
        }

        std::stack<TreeNode *> stack;
        stack.push(pRoot->left);
        stack.push(pRoot->right);

        while (!stack.empty()) {
            auto node1 = stack.top();
            stack.pop();

            auto node2 = stack.top();
            stack.pop();

            if (node1 == nullptr && node2 == nullptr) {
                continue;
            }

            if (node1 == nullptr || node2 == nullptr) {
                return false;
            }

            if (node1->val != node2->val) {
                return false;
            }

            // 成组入栈
            stack.push(node1->left);
            stack.push(node2->right);

            stack.push(node1->right);
            stack.push(node2->left);
        }
        return true;
    }

private:
    bool isSymmetricalReal(TreeNode *left, TreeNode *right) {
        if (left == nullptr || right == nullptr) {
            if (left == nullptr && right == nullptr) {
                return true;
            }
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return isSymmetricalReal(left->left, right->right) && isSymmetricalReal(left->right, right->left);
    }
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->left->left = new TreeNode(8);
    root->right->left->right = new TreeNode(7);
    root->right->right->left = new TreeNode(6);
    root->right->right->right = new TreeNode(5);

    Solution solution;
    std::cout << std::boolalpha;
    std::cout << solution.isSymmetrical(root) << std::endl;
}