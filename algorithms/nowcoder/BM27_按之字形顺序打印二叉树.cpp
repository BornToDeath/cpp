//
// Created by lixiaoqing on 2022/10/20.
//


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > Print(TreeNode *pRoot) {
        /**
         * 方法1：两个栈分别保存奇偶行的结点
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        if (pRoot == nullptr) {
//            return {};
//        }
//        std::vector<std::vector<int>> ans;
//        std::stack<TreeNode *> oddStack, evenStack;
//        oddStack.push(pRoot);
//        int height = 1;
//        while (!oddStack.empty() || !evenStack.empty()) {
//            ans.emplace_back();
//            if ((height & 1) == 1) {
//                while (!oddStack.empty()) {
//                    auto node = oddStack.top();
//                    oddStack.pop();
//                    ans.back().push_back(node->val);
//                    if (node->left) {
//                        evenStack.push(node->left);
//                    }
//                    if (node->right) {
//                        evenStack.push(node->right);
//                    }
//
//                }
//            } else {
//                while (!evenStack.empty()) {
//                    auto node = evenStack.top();
//                    evenStack.pop();
//                    ans.back().push_back(node->val);
//                    if (node->right) {
//                        oddStack.push(node->right);
//                    }
//                    if (node->left) {
//                        oddStack.push(node->left);
//                    }
//                }
//            }
//            ++height;
//        }
//        return ans;

        /**
         * 方法2：一个队列，在奇偶行进行反转
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        if (pRoot == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> ans;
        std::queue<TreeNode *> q;
        q.push(pRoot);
        int height = 1;
        while (!q.empty()) {
            ans.emplace_back();
            const int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if ((height & 1) == 0) {
                std::reverse(ans.back().begin(), ans.back().end());
            }
            ++height;
        }
        return ans;
    }

};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    auto ans = Solution().Print(root);
    for (auto &arr: ans) {
        for (auto e: arr) {
            std::cout << e << ", ";
        }
        std::cout << std::endl;
    }
}