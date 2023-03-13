//
// Created by lixiaoqing on 2023/3/13.
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
    ListNode* deleteNode(ListNode* head, int val) {
        /**
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        if (head == nullptr) {
            return nullptr;
        }
        if (head->val == val) {
            return head->next;
        }
        auto node = head->next, pre = head;
        while (node) {
            if (node->val == val) {
                pre->next = node->next;
                break;
            }
            pre = node;
            node = node->next;
        }
        return head;
    }
};