//
// Created by lixiaoqing on 2023/3/14.
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
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr, *next = head;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};