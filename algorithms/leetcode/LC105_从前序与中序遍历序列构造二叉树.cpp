//
// Created by lixiaoqing on 2022/6/29.
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

#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *buildTree(vector<int> &preorder, int l1, int r1, vector<int> &inorder, int l2, int r2) {
        if (l1 > r1 || l2 > r2) {
            return nullptr;
        }
        auto root = new TreeNode(preorder[l1]);
        int pos = l2;
        while (pos <= r2 && inorder[pos] != preorder[l1]) {
            ++pos;
        }
        int leftSize = pos - l2;
        root->left = buildTree(preorder, l1 + 1, l1 + leftSize, inorder, l2, pos - 1);
        root->right = buildTree(preorder, l1 + leftSize + 1, r1, inorder, pos + 1, r2);
        return root;
    }
};

int main() {
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    auto root = Solution().buildTree(preorder, inorder);
    return 0;
}