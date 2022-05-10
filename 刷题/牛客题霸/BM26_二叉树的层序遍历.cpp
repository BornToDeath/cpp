//
// Created by lixiaoqing on 2022/5/10.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> res;
        std::queue<TreeNode *> _queue;
        _queue.push(root);
        while (!_queue.empty()) {
            auto size = _queue.size();
            vector<int> nums;
            for (auto i = 0; i < size; ++i) {
                auto node = _queue.front();
                _queue.pop();
                nums.emplace_back(node->val);
                if (node->left) {
                    _queue.push(node->left);
                }
                if (node->right) {
                    _queue.push(node->right);
                }
            }
            res.emplace_back(nums);
        }
        return res;
    }
};