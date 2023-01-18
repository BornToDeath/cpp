//
// Created by lixiaoqing on 2022/7/24.
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
    int rob(TreeNode *root) {
        /**
         * 方法：动态规划，时间复杂度 O(n) ，空间复杂度 O(n)
         * 参考：：https://leetcode.cn/problems/house-robber-iii/solution/da-jia-jie-she-iii-by-leetcode-solution/
         * f[x] 表示节点 x 被选中时的权值最大值，g[x] 表示节点 x 没被选中时的权值最大值，则：
         *   f[x] = g[l] + g[r] + x
         *   g[x] = std::max(f[l], g[l]) + std::max(f[r] + g[r])
         */
//        dfs(root);
//        return std::max(f[root], g[root]);

        /**
         * 方法2：在方法1的基础上进行优化，去掉哈希表的内存占用。时间复杂度 O(n) ，空间复杂度 O(n)
         * 由于存在递归，栈空间的空间复杂度 O(n) ，故总的时间复杂度还是 O(n)
         */
        auto ans = dfs2(root);
        return std::max(ans.first, ans.second);
    }

private:
    void dfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        f[root] = g[root->left] + g[root->right] + root->val;
        g[root] = std::max(f[root->left], g[root->left]) + std::max(f[root->right], g[root->right]);
    }

    std::pair<int, int> dfs2(TreeNode *root) {
        if (root == nullptr) {
            return {0, 0};
        }
        auto left = dfs2(root->left);
        auto right = dfs2(root->right);
        std::pair<int, int> ele;
        ele.first = left.second + right.second + root->val;
        ele.second = std::max(left.first, left.second) + std::max(right.first, right.second);
        return ele;
    }

private:
    std::unordered_map<TreeNode *, int> f, g;
};

int main() {
    auto root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    std::cout << Solution().rob(root) << std::endl;
}