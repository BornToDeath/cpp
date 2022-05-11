//
// Created by lixiaoqing on 2022/5/11.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

#include <climits>
#include "TreeNode.h"

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isValidBST(TreeNode *root) {
        /**
         * 二叉搜索树的中序遍历序列一定是严格递增的
         */
        if (!root) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (pre >= root->val) {
            return false;
        }
        pre = root->val;
        return isValidBST(root->right);
    }

private:
    int pre = INT_MIN;
};