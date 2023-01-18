//
// Created by lixiaoqing on 2022/9/29.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

#include <vector>
#include "TreeNode.h"

/**
 * 方法2
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
         * 方法2：
         * 最近公共节点具有如下特征：
         *   1. 如果该节点是o1或o2，则另一节点必在其左右子树中
         *   2. 否则，o1或o2分别在该节点的左右子树中
         */
        if (root == nullptr) {
            return -1;
        }
        if (root->val == o1 || root->val == o2) {
            return root->val;
        }
        auto left = lowestCommonAncestor(root->left, o1, o2);
        auto right = lowestCommonAncestor(root->right, o1, o2);
        if (left == -1) {
            return right;
        }
        if (right == -1) {
            return left;
        }
        return root->val;
    }
};

/**
 * 方法1：
 */
class Solution1 {
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
         * 方法：使用 std::vector 记录节点沿途经过的路径
         */
        if (root == nullptr) {
            return -1;
        }
        std::vector<int> v;
        dfs(root, o1, o2, v);
        for (int i = v1.size() - 1; i >= 0; --i) {
            if (std::find(v2.begin(), v2.end(), v1[i]) != v2.end()) {
                return v1[i];
            }
        }
        return -1;
    }

private:
    void dfs(TreeNode *root, int o1, int o2, std::vector<int> &v) {
        if (root == nullptr || !v1.empty() && !v2.empty()) {
            return;
        }
        v.push_back(root->val);
        if (root->val == o1) {
            v1 = v;
        }
        if (root->val == o2) {
            v2 = v;
        }
        dfs(root->left, o1, o2, v);
        dfs(root->right, o1, o2, v);
        v.pop_back();
    }

private:
    std::vector<int> v1, v2;
};