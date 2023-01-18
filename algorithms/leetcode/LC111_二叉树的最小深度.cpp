//
// Created by lixiaoqing on 2023/1/11.
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

#include <iostream>
#include <queue>
#include "TreeNode.h"

class Solution {
public:
    int minDepth(TreeNode *root) {
        /**
         * 方法1：DFS
         * 时间复杂度 O(N) ，其中 N 是树的节点数
         * 空间复杂度 O(H) ，其中 H 是树的高度
         */
//        if (root == nullptr) {
//            return 0;
//        }
//        if (root->left == nullptr && root->right == nullptr) {
//            return 1;
//        }
//        int min_depth = std::numeric_limits<int>::max();
//        if (root->left != nullptr) {
//            min_depth = std::min(minDepth(root->left), min_depth);
//        }
//        if (root->right != nullptr) {
//            min_depth = std::min(minDepth(root->right), min_depth);
//        }
//        return min_depth + 1;

        /**
         * 方法2：BFS
         * 时间复杂度 O(N) ，其中 N 是树的节点数
         * 空间复杂度 O(N) ，其中 N 是树的节点数
         */
        if (root == nullptr) {
            return 0;
        }
        int min_depth = 0;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            ++min_depth;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    return min_depth;
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return min_depth;
    }
};

int main() {
    auto root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);
    std::cout << Solution().minDepth(root) << std::endl;
    return 0;
}