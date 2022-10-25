//
// Created by lixiaoqing on 2022/10/25.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

#include "TreeNode.h"

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return TreeNode类
     */
    TreeNode *Mirror(TreeNode *pRoot) {
        /**
         * 递归
         * 时间复杂度 O(n) ，空间复杂度 O(数的高度) ，主要是递归时栈空间占用
         */
        if (pRoot == nullptr) {
            return nullptr;
        }
        // 先交换左右子树
        auto left = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = left;
        // 再递归处理左右子树
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};