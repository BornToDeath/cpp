//
// Created by lixiaoqing on 2023/4/27.
//

#include <queue>
#include "TreeNode.h"

/*
 * 方法1: 借助队列
 * 时间复杂度 O(n) , 空间复杂度 O(n)
 */
//class Solution {
//public:
//    TreeNode *increasingBST(TreeNode *root) {
//        inorder(root);
//        if (q.empty()) {
//            return nullptr;
//        }
//        auto head = q.front();
//        auto pre = head;
//        q.pop();
//        while (!q.empty()) {
//            pre->right = q.front();
//            q.pop();
//            pre = pre->right;
//            pre->left = nullptr;
//            pre->right = nullptr;
//        }
//        return head;
//    }
//
//private:
//    void inorder(TreeNode *root) {
//        if (root == nullptr) {
//            return;
//        }
//        inorder(root->left);
//        q.emplace(root);
//        inorder(root->right);
//    }
//
//private:
//    std::queue<TreeNode *> q;
//};

/*
 * 方法2: 原地修改
 * 时间复杂度 O(n) , 空间复杂度 O(1)
 */
class Solution {
public:
    TreeNode *increasingBST(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode *head = increasingBST(root->left);
        if (head == nullptr) {
            head = root;
        } else {
            tail->right = root;
        }
        tail = root;
        root->left = nullptr;
        root->right = increasingBST(root->right);
        return head;
    }

private:
    TreeNode *tail{nullptr};
};


int main() {
    auto root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);
    auto ans = Solution().increasingBST(root);
    return 0;
}
