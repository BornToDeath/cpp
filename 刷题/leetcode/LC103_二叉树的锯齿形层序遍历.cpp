//
// Created by lixiaoqing on 2022/8/22.
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
#include <stack>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        /**
         * 方法1：两个栈，一个从左向右，一个从右向左
         */
//        if (root == nullptr) {
//            return {};
//        }
//        std::vector<std::vector<int>> ans;
//        std::stack<TreeNode *> left2Right, right2Left;
//        left2Right.push(root);
//        while (!left2Right.empty() || !right2Left.empty()) {
//            std::vector<int> v;
//            if (!left2Right.empty()) {
//                while (!left2Right.empty()) {
//                    auto node = left2Right.top();
//                    left2Right.pop();
//                    v.push_back(node->val);
//                    if (node->left) {
//                        right2Left.push(node->left);
//                    }
//                    if (node->right) {
//                        right2Left.push(node->right);
//                    }
//                }
//            } else {
//                while (!right2Left.empty()) {
//                    auto node = right2Left.top();
//                    right2Left.pop();
//                    v.push_back(node->val);
//                    if (node->right) {
//                        left2Right.push(node->right);
//                    }
//                    if (node->left) {
//                        left2Right.push(node->left);
//                    }
//                }
//            }
//            ans.emplace_back(v);
//        }
//        return ans;

        /**
         * 方法2：一个队列，再使用一个标志位记录是从左到右还是从右到左
         */
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> ans;
        int height = 1;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            std::vector<int> v;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                v.emplace_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if ((height & 1) == 0) {  // 偶数行
                std::reverse(v.begin(), v.end());
            }
            ans.emplace_back(v);
            ++height;
        }
        return ans;
    }
};