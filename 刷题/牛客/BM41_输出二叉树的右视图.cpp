//
// Created by lixiaoqing on 2022/5/15.
//

#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    vector<int> solve(vector<int> &xianxu, vector<int> &zhongxu) {
        auto root = constructBinaryTree(xianxu, 0, xianxu.size() - 1, zhongxu, 0, zhongxu.size() - 1);
        if (!root) {
            return {};
        }
        std::vector<int> res;
        std::queue<TreeNode *> _queue;
        _queue.push(root);
        while (!_queue.empty()) {
            auto size = _queue.size();
            for (auto i = 0; i < size; ++i) {
                auto node = _queue.front();
                _queue.pop();
                if (node->right) {
                    _queue.push(node->right);
                }
                if (node->left) {
                    _queue.push(node->left);
                }
                if (i == 0) {
                    res.emplace_back(node->val);
                }
            }
        }
        return res;
    }

private:
    TreeNode *
    constructBinaryTree(vector<int> &preorder, int start, int end, vector<int> &inorder, int left, int right) {
        if (start > end || left > right) {
            return nullptr;
        }
        auto root = new TreeNode(preorder[start]);
        int rootIndex = left;
        while (rootIndex <= right && inorder[rootIndex] != preorder[start]) {
            ++rootIndex;
        }
        int leftCount = rootIndex - left;
        root->left = constructBinaryTree(preorder, start + 1, start + leftCount, inorder, left, rootIndex - 1);
        root->right = constructBinaryTree(preorder, start + leftCount + 1, end, inorder, rootIndex + 1, right);
        return root;
    }
};

int main() {
    std::vector<int> preorder = {1, 2, 4, 5, 3};
    std::vector<int> inorder = {4, 2, 5, 1, 3};
    auto nums = Solution().solve(preorder, inorder);
    for (auto num: nums) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}