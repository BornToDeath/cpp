//
// Created by lixiaoqing on 2022/8/4.
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
#include <unordered_map>
#include "TreeNode.h"

class Solution {
public:
    int pathSum(TreeNode *root, int targetSum) {
        /**
         * 方法1：递归。
         * 时间复杂度O(n^2)，空间复杂度O(n)
         */
//        if (root == nullptr) {
//            return 0;
//        }
//        int count = rootSum(root, targetSum);
//        count += pathSum(root->left, targetSum);
//        count += pathSum(root->right, targetSum);
//        return count;

        /**
         * 方法2：前缀和，见：https://leetcode.cn/problems/path-sum-iii/solution/lu-jing-zong-he-iii-by-leetcode-solution-z9td/
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        dp[0] = 1;
        return dfs(root, 0, targetSum);
    }

private:
    int dfs(TreeNode *root, long sum, int target) {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        sum += root->val;
        if (dp.count(sum - target)) {
            count = dp[sum - target];
        }
        ++dp[sum];
        count += dfs(root->left, sum, target);
        count += dfs(root->right, sum, target);
        --dp[sum];
        return count;
    }

    // targetSum 有可能溢出，需要用 long
    int rootSum(TreeNode *root, long targetSum) {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        if (root->val == targetSum) {
            ++count;
        }
        count += rootSum(root->left, targetSum - root->val);
        count += rootSum(root->right, targetSum - root->val);
        return count;
    }

private:
    // 前缀和，key 是当前节点到根节点的路径和，value 是 key 的个数
    std::unordered_map<long, int> dp;
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(-2);
    root->left->left->left = new TreeNode(-1);
    std::cout << Solution().pathSum(root, 3) << std::endl;
    return 0;
}