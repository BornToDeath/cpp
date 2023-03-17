//
// Created by lixiaoqing on 2023/3/17.
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

#include <vector>
#include "TreeNode.h"

using std::vector;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int target) {
        dfs(root, target);
        return ans;
    }

private:
    void dfs(TreeNode *root, int target) {
        if (root == nullptr) {
            return;
        }
        path.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            ans.emplace_back(path);
        }
        dfs(root->left, target - root->val);
        dfs(root->right, target - root->val);
        path.pop_back();
    }

private:
    std::vector<std::vector<int>> ans;
    std::vector<int> path;
};