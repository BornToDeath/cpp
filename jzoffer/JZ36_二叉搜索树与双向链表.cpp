//
// Created by lixiaoqing on 2022/3/10.
//

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
    TreeNode *Convert(TreeNode *pRootOfTree) {
        if (pRootOfTree == nullptr) {
            return nullptr;
        }
        // 调整左子树
        auto head = Convert(pRootOfTree->left);
        // 如果头结点为空，则当前节点为头结点
        if (head == nullptr) {
            head = pRootOfTree;
        }
        // 调整左右指针
        pRootOfTree->left = tail;
        if (tail) {
            tail->right = pRootOfTree;
        }
        // 调整尾结点
        tail = pRootOfTree;
        // 调整右子树
        Convert(pRootOfTree->right);
        return head;
    }

private:
    TreeNode *tail = nullptr;
};

int main() {
    auto root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->right = new TreeNode(14);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(16);

    Solution solution;
    auto head = solution.Convert(root);
    return 0;
}