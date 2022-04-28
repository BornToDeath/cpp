//
// Created by lixiaoqing on 2022/3/9.
//

#include <iostream>
#include "TreeNode.h"

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param p int整型
     * @param q int整型
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        int value = root->val;
        if (value == p || value == q) {
            return value;
        }
        if (value > p && value < q || value > q && value < p) {
            return value;
        }
        if (value < p) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return lowestCommonAncestor(root->left, p, q);
    }
};

int main() {
    auto root = new TreeNode(7);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right = new TreeNode(12);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    Solution solution;
    std::cout << solution.lowestCommonAncestor(root, 12, 11) << std::endl;
}