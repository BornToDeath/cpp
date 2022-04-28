//
// Created by lixiaoqing on 2022/4/28.
//

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    bool isSame(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr || root2 == nullptr) {
            if (root1 == nullptr && root2 == nullptr) {
                return true;
            }
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
    }
};

int main() {
    auto root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(3);

    auto root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(4);

    std::cout << std::boolalpha;
    std::cout << Solution().isSame(root1, root2) << std::endl;
}