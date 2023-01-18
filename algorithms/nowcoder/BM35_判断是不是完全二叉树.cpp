//
// Created by lixiaoqing on 2022/5/11.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

#include <queue>
#include "TreeNode.h"

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode *root) {
        if (!root) {
            return true;
        }
        bool end = false;
        std::queue<TreeNode *> _queue;
        _queue.push(root);
        while (!_queue.empty()) {
            auto size = _queue.size();
            for (auto i = 0; i < size; ++i) {
                auto node = _queue.front();
                _queue.pop();
                if (!node) {
                    end = true;
                } else {
                    if (end) {
                        return false;
                    }
                    _queue.push(node->left);
                    _queue.push(node->right);
                }
            }
        }
        return true;
    }
};