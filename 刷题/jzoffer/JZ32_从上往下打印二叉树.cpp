//
// Created by lixiaoqing on 2022/3/3.
//

#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<int> nums;
        std::queue<TreeNode*> _queue;
        _queue.push(root);
        while (!_queue.empty()) {
            int size = _queue.size();
            while (size > 0) {
                auto node = _queue.front();
                _queue.pop();
                nums.emplace_back(node->val);
                if (node->left) {
                    _queue.push(node->left);
                }
                if (node->right) {
                    _queue.push(node->right);
                }
                --size;
            }
        }
        return nums;
    }
};