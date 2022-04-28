//
// Created by lixiaoqing on 2022/4/28.
//

#include <iostream>
#include <vector>
#include "TreeNode.h"

class Solution {
public:
    std::vector<int> postOrder(TreeNode *root) {
        _postOrder(root);
        return res;
    }

private:
    void _postOrder(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        _postOrder(root->left);
        _postOrder(root->right);
        res.emplace_back(root->val);
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

    auto res = Solution().postOrder(root);
    for (auto num: res) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}