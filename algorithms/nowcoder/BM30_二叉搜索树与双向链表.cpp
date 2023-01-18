//
// Created by lixiaoqing on 2022/10/24.
//

class Solution {
public:
    TreeNode *Convert(TreeNode *pRootOfTree) {
        /**
         * 递归。
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        if (pRootOfTree == nullptr) {
            return nullptr;
        }
        // 先处理左子树
        auto head = Convert(pRootOfTree->left);
        if (head == nullptr) {
            head = pRootOfTree;
        }
        // 处理指针关系
        pRootOfTree->left = tail;
        if (tail) {
            tail->right = pRootOfTree;
        }
        tail = pRootOfTree;
        // 再处理右子树
        Convert(pRootOfTree->right);
        return head;
    }

private:
    TreeNode *tail = nullptr;
};
