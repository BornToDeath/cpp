//
// Created by lixiaoqing on 2022/6/13.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

#include <vector>
#include <numeric>
#include "TreeNode.h"

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型
     */
    int sumNumbers(TreeNode *root) {
        getNumbers(root, 0);
        return sum;
    }

private:
    void getNumbers(TreeNode *root, int num) {
        if (root == nullptr) {
            return;
        }
        num = num * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += num;
            return;
        }
        if (root->left) {
            getNumbers(root->left, num);
        }
        if (root->right) {
            getNumbers(root->right, num);
        }
    }

private:
    int sum = 0;
};