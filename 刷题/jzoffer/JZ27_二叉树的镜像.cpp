//
// Created by lixiaoqing on 2022/3/3.
//

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
     * @param pRoot TreeNode类
     * @return TreeNode类
     */
    TreeNode *Mirror(TreeNode *pRoot) {
        /**
         * 方法1：空间复杂度O(n)
         */
//        if (pRoot == nullptr) {
//            return nullptr;
//        }
//        auto mirrorRoot = new TreeNode(pRoot->val);
//        mirrorRoot->left = Mirror(pRoot->right);
//        mirrorRoot->right = Mirror(pRoot->left);
//        return mirrorRoot;

        /**
         * 方法2：空间复杂度O(1)
         */
        if (pRoot == nullptr) {
            return nullptr;
        }
        auto temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};