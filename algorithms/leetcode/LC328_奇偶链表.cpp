//
// Created by lixiaoqing on 2022/9/16.
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
    ListNode *oddEvenList(ListNode *head) {
        /**
         * 方法：先分离奇偶节点，然后拼接
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        if (head == nullptr) {
            return head;
        }
        auto evenHead = head->next, odd = head, even = head->next;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};