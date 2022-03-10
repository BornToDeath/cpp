//
// Created by lixiaoqing on 2022/3/10.
//

#include <cstdio>
#include <vector>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode) {
        /**
         * 1. 有右子树：则右子树最左边的结点就是下一个结点
         * 2. 没有右子树：
         *   2.1 是父结点的左孩子：则父节点是下一个结点
         *   2.2 是父结点的右孩子：则向上查找，直到某一结点是其父结点的左孩子，则该父结点是下一个结点。如果没有这样的结点存在，则返回空
         */

        if (pNode == nullptr) {
            return nullptr;
        }
        // 1
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        }
        // 2
        while (pNode->next) {
            if (pNode->next->left == pNode) {
                return pNode->next;
            }
            pNode = pNode->next;
        }
        return nullptr;
    }
};