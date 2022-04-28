//
// Created by lixiaoqing on 2022/3/8.
//

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    bool IsBalanced_Solution(TreeNode *pRoot) {
        /**
         * 方法1
         */
        return depthOfTree1(pRoot) != -1;

        /**
         * 方法2
         */
//        if (pRoot == nullptr) {
//            return true;
//        }
//        if (!IsBalanced_Solution(pRoot->left)) {
//            return false;
//        }
//        if (!IsBalanced_Solution(pRoot->right)) {
//            return false;
//        }
//        auto leftDepth = depthOfTree2(pRoot->left);
//        auto rightDepth = depthOfTree2(pRoot->right);
//        return (std::abs(leftDepth - rightDepth) <= 1);
    }

private:
    int depthOfTree1(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = depthOfTree1(root->left);
        if (leftDepth == -1) {
            return -1;
        }
        int rightDepth = depthOfTree1(root->right);
        if (rightDepth == -1) {
            return rightDepth;
        }
        int diff = std::abs(leftDepth - rightDepth);
        return (diff > 1) ? -1 : (1 + std::max(leftDepth, rightDepth));
    }

    int depthOfTree2(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(depthOfTree2(root->left), depthOfTree2(root->right));
    }
};
