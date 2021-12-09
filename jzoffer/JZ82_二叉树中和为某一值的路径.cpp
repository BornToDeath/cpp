//
// Created by lixiaoqing on 2021/12/9.
//

#include <iostream>
#include "TreeNode.h"

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == sum) {
                return true;
            }
            return false;
        }
        auto flag = hasPathSum(root->left, sum-root->val);
        if (flag) {
            return true;
        }

        flag = hasPathSum(root->right, sum-root->val);
        return flag;
    }
};

int main() {
    auto root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(11);
    root->left->right->left = new TreeNode(2);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(9);

    Solution solution;
    std::cout << std::boolalpha;
    std::cout << solution.hasPathSum(root, 22) << std::endl;

    return 0;
}