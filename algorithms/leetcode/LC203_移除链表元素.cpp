//
// Created by lixiaoqing on 2023/1/16.
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
    ListNode *removeElements(ListNode *head, int val) {
        /**
         * 方法1：利用虚拟头结点
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        auto newHead = new ListNode(-1);
//        newHead->next = head;
//        auto cur = newHead;
//        while (cur->next) {
//            if (cur->next->val == val) {
//                cur->next = cur->next->next;
//            } else {
//                cur = cur->next;
//            }
//        }
//        return newHead->next;

        /**
         * 方法2：不使用虚拟头结点
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        while (head && head->val == val) {
            head = head->next;
        }
        auto cur = head;
        while (cur && cur->next) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};