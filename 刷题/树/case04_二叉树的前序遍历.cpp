//
// Created by lixiaoqing on 2022/4/28.
//

#include <iostream>
#include <vector>
#include "TreeNode.h"

class Solution {
public:
    std::vector<int> preOrder(TreeNode *root) {
        _preOrder(root);
        return res;
    }

private:
    void _preOrder(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        res.emplace_back(root->val);
        _preOrder(root->left);
        _preOrder(root->right);
    }

private:
    std::vector<int> res;
};

int main() {
    auto root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->left->left = new TreeNode(4);
    root->right->left->right = new TreeNode(5);

    auto res = Solution().preOrder(root);
    for (auto num: res) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}