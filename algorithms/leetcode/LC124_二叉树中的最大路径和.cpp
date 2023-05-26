//
// Created by lixiaoqing on 2023/5/26.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        /*
         * DFS, 注意: 此题中路径两端并不要求是叶子节点!
         * 1. 先计算各个节点的最大贡献
         * 2. 再计算各个节点的最大路径和
         * 参考: https://leetcode.cn/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-leetcode-/
         * 时间复杂度 O(n) , 空间复杂度 O(n) , 最坏情况下, 递归层数等于二叉树的高度
         */
        dfs(root);
        return maxSum;
    }

private:
    /*
     * 计算 root 作为根节点时的最大贡献
     */
    int dfs(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        // 计算左子树最大贡献, 如果为负数还不如不贡献
        auto leftMaxGain = std::max(dfs(root->left), 0);

        // 计算右子树最大贡献, 如果为负数还不如不贡献
        auto rightMaxGain = std::max(dfs(root->right), 0);

        // 将当前 root 作为根节点时的路径最大和与 maxSum 进行比较. 当计算 root 的最大路径和时, 左右子树的贡献都要考虑
        maxSum = std::max(maxSum, root->val + leftMaxGain + rightMaxGain);

        // 返回 root 作为根节点时的最大贡献, 供其父节点使用
        return root->val + std::max(leftMaxGain, rightMaxGain);
    }

private:
    int maxSum{INT_MIN};
};

int main() {
    auto root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

//    auto root = new TreeNode(5);
//    root->left = new TreeNode(4);
//    root->left->left = new TreeNode(11);
//    root->left->left->left = new TreeNode(7);
//    root->left->left->right = new TreeNode(2);
//    root->right = new TreeNode(8);
//    root->right->left = new TreeNode(13);
//    root->right->right = new TreeNode(4);
//    root->right->right->right = new TreeNode(1);

    std::cout << Solution().maxPathSum(root) << std::endl;
    return 0;
}