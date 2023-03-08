//
// Created by lixiaoqing on 2023/3/8.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include "TreeNode.h"

using std::vector;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *buildTree(vector<int> &preorder, int pos, vector<int> &inorder, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        auto root = new TreeNode(preorder[pos]);
        int index = std::find(inorder.begin(), inorder.end(), preorder[pos]) - inorder.begin();
        root->left = buildTree(preorder, pos + 1, inorder, l, index - 1);
        root->right = buildTree(preorder, pos + index - l + 1, inorder, index + 1, r);
        return root;
    }
};

int main() {
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    Solution().buildTree(preorder, inorder);
    return 0;
}