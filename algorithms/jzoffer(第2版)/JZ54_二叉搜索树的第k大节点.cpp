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

#include "TreeNode.h"

class Solution {
public:
    int kthLargest(TreeNode *root, int k) {
        /*
         * 方法1：先遍历右子树，再遍历左子树
         * 时间复杂度 O(n) , 空间复杂度 O(logn)
         */
//        if (root == nullptr) {
//            return -1;
//        }
//        int num = -1;
//        dfs(root, k, num);
//        return num;

        /*
         * 方法2：思路同方法1，只是不一样的写法
         * 时间复杂度 O(n) , 空间复杂度 O(logn)
         */
        if (root == nullptr) {
            return -1;
        }
        auto ret = kthLargest(root->right, k);
        if (ret != -1) {
            return ret;
        }
        ++index;
        if (index == k) {
            return root->val;
        }
        return kthLargest(root->left, k);
    }

private:
    bool dfs(TreeNode *root, int &k, int &num) {
        if (root == nullptr) {
            return false;
        }
        if (dfs(root->right, k, num)) {
            return true;
        }
        if (k == 1) {
            num = root->val;
            return true;
        }
        --k;
        return dfs(root->left, k, num);
    }

private:
    int index{0};
};