//
// Created by lixiaoqing on 2022/9/19.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "ListNode.h"

class Solution {
public:
    void deleteNode(ListNode* node) {
        /**
         * 方法1：将node之后的结点逐渐前移
         */
        auto pre = node;
        while (node->next) {
            node->val = node->next->val;
            pre = node;
            node = node->next;
        }
        pre->next = nullptr;

        /**
         * 方法2：无需前移，将node与node->next交换
         */
        node->val = node->next->val;
        node->next = node->next->next;
    }
};