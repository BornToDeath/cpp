//
// Created by lixiaoqing on 2022/6/7.
//

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

#include <iostream>
#include "TreeNode.h"

class Balance {
public:
    bool isBalance(TreeNode *root) {
        return _isBalance(root) != -1;
    }

private:
    int _isBalance(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left = _isBalance(root->left);
        if (left == -1) {
            return -1;
        }
        int right = _isBalance(root->right);
        if (right == -1) {
            return -1;
        }
        if (std::abs(left - right) > 1) {
            return -1;
        }
        return 1 + std::max(left, right);
    }
};