//
// Created by lixiaoqing on 2022/5/10.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     */
    vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> res;
        inOrder(root, res);
        return res;
    }

private:
    void inOrder(TreeNode *root, std::vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        if (root->left) {
            inOrder(root->left, res);
        }
        res.emplace_back(root->val);
        if (root->right) {
            inOrder(root->right, res);
        }
    }
};