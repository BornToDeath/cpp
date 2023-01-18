//
// Created by lixiaoqing on 2022/4/28.
//

#include <iostream>
#include "TreeNode.h"

class Solution {
public:
    bool isSubTree(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr) {
            return false;
        }
        if (_isSubTree(root1, root2)) {
            return true;
        }
        return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
    }

private:
    bool _isSubTree(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr || root2 == nullptr) {
            if (root1 == nullptr && root2 == nullptr) {
                return true;
            }
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return _isSubTree(root1->left, root2->left) && _isSubTree(root1->right, root2->right);
    }
};

int main() {
    auto root1 = new TreeNode(3);
    root1->left = new TreeNode(4);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);
    root1->right = new TreeNode(5);

    auto root2 = new TreeNode(4);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(2);

    std::cout << std::boolalpha;
    std::cout << Solution().isSubTree(root1, root2) << std::endl;
    return 0;
}