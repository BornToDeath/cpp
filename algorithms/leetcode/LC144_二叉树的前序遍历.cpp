//
// Created by lixiaoqing on 2023/1/12.
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
#include <stack>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        /**
         * 方法1：递归
         * 时间复杂度 O(n) ，空间复杂度 O(logn)
         */
//        if (root == nullptr) {
//            return {};
//        }
//        nums.emplace_back(root->val);
//        preorderTraversal(root->left);
//        preorderTraversal(root->right);
//        return nums;

        /**
         * 方法2：迭代
         * 时间复杂度 O(n) ，空间复杂度 O(logn)
         */
//        std::vector<int> res;
//        auto node = root;
//        std::stack<TreeNode *> _stack;
//        while (node || !_stack.empty()) {
//            if (node == nullptr) {
//                node = _stack.top();
//                _stack.pop();
//            }
//            if (node->right) {
//                _stack.push(node->right);
//            }
//            res.emplace_back(node->val);
//            node = node->left;
//        }
//        return res;

        /**
         * 方法3：Morris 遍历
         * 参考：https://leetcode.cn/problems/binary-tree-preorder-traversal/solution/leetcodesuan-fa-xiu-lian-dong-hua-yan-shi-xbian-2/
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        std::vector<int> ans;
        TreeNode *cur = root;
        while (cur) {
            // 如果有左子树，则先处理左子树的最右侧节点
            if (cur->left) {
                // node 代表左子树的最右侧节点
                auto node = cur->left;
                // 寻找左子树最右侧节点
                while (node->right && node->right != cur) {
                    node = node->right;
                }
                // 如果最右侧节点没有指向根节点，则修改其右子树
                if (node->right == nullptr) {
                    // 将最右侧节点的右子树指向根节点
                    node->right = cur;
                    // 非叶子节点加入到数组中
                    ans.emplace_back(cur->val);
                    // 继续处理左子树（的最右侧节点）
                    cur = cur->left;
                    continue;
                }
                // 当最右侧节点的右子树指向根节点时，说明此时已经回到了根节点，说明已经处理完了左子树的最右侧节点了，恢复其右子树的指向
                node->right = nullptr;
            } else {
                // 叶子节点加入到数组中
                ans.emplace_back(cur->val);
            }
            cur = cur->right;
        }
        return ans;
    }

private:
    std::vector<int> nums;
};


int main() {
//    auto root = new TreeNode(3);
//    root->left = new TreeNode(1);
//    root->left->right = new TreeNode(2);

    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    auto ans = Solution().preorderTraversal(root);
    for (auto o: ans) {
        std::cout << o << ", ";
    }
    std::cout << std::endl;
    return 0;
}