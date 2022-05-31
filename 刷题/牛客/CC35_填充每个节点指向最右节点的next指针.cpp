//
// Created by lixiaoqing on 2022/5/31.
//

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

#include <queue>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        std::queue<TreeLinkNode *> _queue;
        _queue.push(root);
        while (!_queue.empty()) {
            int size = _queue.size();
            for (int i = 0; i < size; ++i) {
                auto node = _queue.front();
                _queue.pop();
                if (node->left) {
                    _queue.push(node->left);
                }
                if (node->right) {
                    _queue.push(node->right);
                }
                if (i != size - 1) {
                    node->next = _queue.front();
                }
            }
        }
    }
};

int main() {
    auto root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);
    Solution().connect(root);
    return 0;
}