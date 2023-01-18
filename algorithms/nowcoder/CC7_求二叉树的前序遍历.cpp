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

#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector
     */
    vector<int> preorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<int> res;
        preOrder(root, res);
        return res;
    }

private:
    void preOrder(TreeNode *root, std::vector<int> &arr) {
        if (root == nullptr) {
            return;
        }
        arr.push_back(root->val);
        preOrder(root->left, arr);
        preOrder(root->right, arr);
    }
};