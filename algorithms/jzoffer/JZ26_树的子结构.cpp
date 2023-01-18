//
// Created by lixiaoqing on 2022/3/10.
//

#include <iostream>
#include "TreeNode.h"

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

class Solution {
public:
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }
        return realHasSubTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }

private:
    bool realHasSubTree(TreeNode *root1, TreeNode *root2) {
        if (root2 == nullptr) {
            return true;
        }
        if (root1 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return realHasSubTree(root1->left, root2->left) && realHasSubTree(root1->right, root2->right);
    }
};

int main() {
    auto root1 = new TreeNode(8);
    root1->left = new TreeNode(8);
    root1->left->left = new TreeNode(9);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(4);
    root1->left->right->right = new TreeNode(7);
    root1->right = new TreeNode(7);

    auto root2 = new TreeNode(2);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(7);

    Solution solution;
    std::cout << std::boolalpha;
    std::cout << solution.HasSubtree(root1, root2) << std::endl;
    return 0;
}