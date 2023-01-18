//
// Created by lixiaoqing on 2022/6/15.
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

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto head = new ListNode(-1);
        auto node = head;
        int x = 0, y = 0, carry = 0;
        while (l1 || l2 || carry) {
            x = l1 ? l1->val : 0;
            y = l2 ? l2->val : 0;
            node->next = new ListNode((x + y + carry) % 10);
            carry = (x + y + carry) / 10;
            node = node->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        return head->next;
    }
};