//
// Created by lixiaoqing on 2023/5/4.
//

#include <iostream>
#include <unordered_set>
#include "TreeNode.h"

class Solution {
public:
    bool findTarget(TreeNode *root, int k) {
        if (root == nullptr) {
            return false;
        }
        if (uset.count(k - root->val)) {
            return true;
        }
        uset.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }

private:
    std::unordered_set<int> uset;
};

int main() {
    auto root = new TreeNode(2);
    root->left = new TreeNode(0);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(-4);
    root->left->right = new TreeNode(1);
    std::cout << Solution().findTarget(root, -1) << std::endl;
    return 0;
}