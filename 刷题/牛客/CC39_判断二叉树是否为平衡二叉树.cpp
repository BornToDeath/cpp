//
// Created by lixiaoqing on 2022/5/31.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isBalanced(TreeNode *root) {
        /**
         * 方法1：递归。但是重复计算了
         */
//        if (root == nullptr) {
//            return true;
//        }
//        if (std::abs(getHeight(root->left) - getHeight(root->right)) > 1) {
//            return false;
//        }
//        return isBalanced(root->left) && isBalanced(root->right);

        /**
         * 方法2：在方法1的基础上提高效率
         */
//        return _isBalanced(root).first;

        /**
         * 方法3：在方法2的基础上再优化
         */
        return getHeight2(root) != -1;
    }

private:
    int getHeight2(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        auto left = getHeight2(root->left);
        if (left == -1) {
            return -1;
        }
        auto right = getHeight2(root->right);
        if (right == -1) {
            return -1;
        }
        if (std::abs(left - right) > 1) {
            return -1;
        }
        return 1 + std::max(left, right);
    }

    std::pair<bool, int> _isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return {true, 0};
        }
        auto res1 = _isBalanced(root->left);
        if (!res1.first) {
            return {false, -1};
        }
        auto res2 = _isBalanced(root->right);
        if (!res2.first) {
            return {false, -1};
        }
        if (std::abs(res1.second - res2.second) > 1) {
            return {false, -1};
        }
        return {true, 1 + std::max(res1.second, res2.second)};
    }

    int getHeight(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(getHeight(root->left), getHeight(root->right));
    }
};

int main() {
    auto root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    std::cout << std::boolalpha
              << Solution().isBalanced(root)
              << std::endl;
    return 0;
}