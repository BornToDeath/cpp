//
// Created by lixiaoqing on 2023/3/15.
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

#include "TreeNode.h"

class Solution {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        /**
         * 方法1：DFS
         * 时间复杂度 O(mn) ，空间复杂度 O(n) ，其中 m 为 A 的节点数，n 为 B 的节点数
         */
        if (A == nullptr || B == nullptr) {
            if (A == nullptr && B == nullptr) {
                return true;
            }
            return false;
        }
        return isSubTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

private:
    bool isSubTree(TreeNode *root1, TreeNode *root2) {
        if (root2 == nullptr) {
            return true;
        } else if (root1 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return isSubTree(root1->left, root2->left) && isSubTree(root1->right, root2->right);
    }
};