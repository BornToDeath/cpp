//
// Created by lixiaoqing on 2023/3/2.
//

#include <vector>
#include <unordered_map>
#include <iostream>
#include "TreeNode.h"

using namespace std;

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

#if 0
/**
 * 方法1：借助哈希表
 * 时间复杂度 O(n) ，空间复杂度 O(n)
 */
class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        std::vector<int> ans;
        dfs(root);
        for (auto o: _map) {
            if (o.second == max) {
                ans.emplace_back(o.first);
            }
        }
        return ans;
    }

private:
    void dfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        ++_map[root->val];
        max = std::max(max, _map[root->val]);
        dfs(root->left);
        dfs(root->right);
    }

private:
    std::unordered_map<int, int> _map;
    int max{0};
};
#endif

/**
 * 方法2：中序遍历：Morris 遍历
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/solution/er-cha-sou-suo-shu-zhong-de-zhong-shu-by-leetcode-/
 * 时间复杂度 O(n) ，空间复杂度 O(1)
 */
class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        auto cur = root;
        while (cur) {
            if (cur->left) {
                auto node = cur->left;
                while (node->right && node->right != cur) {
                    node = node->right;
                }
                if (node->right == nullptr) {
                    node->right = cur;
                    cur = cur->left;
                    continue;
                }
                update(cur->val);  // 处理非叶子节点
                node->right = nullptr;
            } else {
                update(cur->val);  // 处理叶子节点
            }
            cur = cur->right;
        }
        return answer;
    }

private:
    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            count = 1;
            base = x;
        }
        if (count == maxCount) {
            answer.push_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            answer = vector<int>{base};
        }
    }

private:
    int base, count, maxCount;
    vector<int> answer;
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->left->left->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(1);
    auto ans = Solution().findMode(root);
    for (auto n: ans) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
    return 0;
}