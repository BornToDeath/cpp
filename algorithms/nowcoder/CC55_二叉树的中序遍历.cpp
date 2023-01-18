//
// Created by lixiaoqing on 2022/6/1.
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

using namespace std;

class Solution {
public:
    /**
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