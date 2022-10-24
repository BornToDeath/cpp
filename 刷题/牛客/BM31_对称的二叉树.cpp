//
// Created by lixiaoqing on 2022/10/24.
//

#include <queue>
#include <stack>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode *pRoot) {
        /**
         * 方法1：递归
         */
//        return isSymmetrical(pRoot, pRoot);

        /**
         * 方法2：迭代：利用队列
         */
//        if (pRoot == nullptr) {
//            return true;
//        }
//        std::queue<TreeNode *> q1, q2;
//        q1.push(pRoot);
//        q2.push(pRoot);
//        while (!q1.empty() && !q2.empty()) {
//            const int size = q1.size();
//            for (int i = 0; i < size; ++i) {
//                auto node1 = q1.front(), node2 = q2.front();
//                q1.pop();
//                q2.pop();
//                if (node1->val != node2->val) {
//                    return false;
//                }
//                if (node1->left && node2->right) {
//                    q1.push(node1->left);
//                    q2.push(node2->right);
//                } else if (node1->left == nullptr && node2->right == nullptr) { ;
//                } else {
//                    return false;
//                }
//                if (node1->right && node2->left) {
//                    q1.push(node1->right);
//                    q2.push(node2->left);
//                } else if (node1->right == nullptr && node2->left == nullptr) { ;
//                } else {
//                    return false;
//                }
//            }
//        }
//        if (!q1.empty() || !q2.empty()) {
//            return false;
//        }
//        return true;

        /**
         * 方法3：迭代：利用栈
         */
        std::stack<TreeNode *> _stack;
        _stack.push(pRoot);
        _stack.push(pRoot);
        while (!_stack.empty()) {
            auto node1 = _stack.top();
            _stack.pop();
            auto node2 = _stack.top();
            _stack.pop();
            if (node1 == nullptr || node2 == nullptr) {
                if (node1 == nullptr && node2 == nullptr) {
                    continue;
                }
                return false;
            }
            if (node1->val != node2->val) {
                return false;
            }
            // 成组入栈
            _stack.push(node1->left);
            _stack.push(node2->right);

            _stack.push(node1->right);
            _stack.push(node2->left);
        }
        return true;
    }

private:
    bool isSymmetrical(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr || root2 == nullptr) {
            return root1 == nullptr && root2 == nullptr;
        }
        if (root1->val != root2->val) {
            return false;
        }
        return isSymmetrical(root1->left, root2->right) && isSymmetrical(root1->right, root2->left);
    }

};