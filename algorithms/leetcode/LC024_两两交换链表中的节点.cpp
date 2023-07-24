//
// Created by lixiaoqing on 2023/7/24.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include "ListNode.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        /*
         * 时间复杂度 O(n), 空间复杂度 O(1)
         */
        auto dummyHead = new ListNode(-1);
        dummyHead->next = head;
        auto node = dummyHead;

        while (node->next && node->next->next) {
            auto reverseNode = reverse(node->next);
            node->next = reverseNode;
            node = node->next->next;
        }

        return dummyHead->next;
    }

private:
    ListNode *reverse(ListNode *head) {
        auto next = head->next;
        head->next = next->next;
        next->next = head;
        return next;
    }
};