//
// Created by lixiaoqing on 2023/1/29.
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
#include <vector>
#include <string>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        /**
         * 方法1：DFS
         * 时间复杂度 O(N^2) ，空间复杂度 O(N^2)
         */
//        std::vector<std::string> ans;
//        binaryTreePath(root, "", ans);
//        return ans;

        /**
         * 方法2：BFS
         * 时间复杂度 O(N^2) ，空间复杂度 O(N^2)
         */
        if (root == nullptr) {
            return {};
        }
        std::vector<std::string> ans;
        std::queue<TreeNode *> nodeQueue;
        std::queue<std::string> pathQueue;
        nodeQueue.push(root);
        pathQueue.push(std::to_string(root->val));
        while (!nodeQueue.empty()) {
            auto node = nodeQueue.front();
            nodeQueue.pop();
            auto path = pathQueue.front();
            pathQueue.pop();
            if (node->left == nullptr && node->right == nullptr) {
                ans.emplace_back(path);
                continue;
            }
            if (node->left) {
                nodeQueue.push(node->left);
                pathQueue.push(path + "->" + std::to_string(node->left->val));
            }
            if (node->right) {
                nodeQueue.push(node->right);
                pathQueue.push(path + "->" + std::to_string(node->right->val));
            }
        }
        return ans;
    }

private:
    void binaryTreePath(TreeNode *root, std::string path, std::vector<std::string> &ans) {
        if (root == nullptr) {
            return;
        }
        path.append(std::to_string(root->val));
        if (root->left == nullptr && root->right == nullptr) {
            // 是叶子节点
            ans.emplace_back(path);
        } else {
            // 非叶子节点
            path.append("->");
        }
        binaryTreePath(root->left, path, ans);
        binaryTreePath(root->right, path, ans);
    }

};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    auto ans = Solution().binaryTreePaths(root);
    for (auto &o : ans) {
        std::cout << o << std::endl;
    }
    return 0;
}