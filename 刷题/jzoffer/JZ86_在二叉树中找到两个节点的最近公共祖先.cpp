//
// Created by lixiaoqing on 2022/3/16.
//

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
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode *root, int o1, int o2) {
        /**
         * 最近公共节点具有如下特征：
         *   1. 如果该节点是o1或o2，则另一节点必在其左右子树中
         *   2. 否则，o1或o2分别在该节点的左右子树中
         */
        auto node = dfs(root, o1, o2);
        return node->val;
    }

private:
    TreeNode *dfs(TreeNode *root, int o1, int o2) {
        if (root == nullptr || root->val == o1 || root->val == o2) {
            return root;
        }
        auto left = dfs(root->left, o1, o2);
        auto right = dfs(root->right, o1, o2);
        // 如果左子树为空，则返回右子树，不管右子树是否为空
        if (left == nullptr) {
            return right;
        }
        // 如果左子树不为空而右子树为空，则返回左子树
        if (right == nullptr) {
            return left;
        }
        // 如果左右子树都不为空，则返回根节点
        return root;
    }
};

int main() {
    return 0;
}