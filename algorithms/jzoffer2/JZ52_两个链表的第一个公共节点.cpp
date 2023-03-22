//
// Created by lixiaoqing on 2023/3/22.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /**
         * 方法1：先计算两个链表长度，然后快慢指针
         * 时间复杂度 O(m + n) ，空间复杂度 O(1)
         */
        auto lenA = listLength(headA);
        auto lenB = listLength(headB);
        while (lenA > lenB) {
            headA = headA->next;
            --lenA;
        }
        while (lenB > lenA) {
            headB = headB->next;
            --lenB;
        }
        while (headA) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;

        /**
         * 方法2：双指针，很巧妙
         * https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/liang-ge-lian-biao-de-di-yi-ge-gong-gong-pzbs/
         * 时间复杂度 O(m + n) ，空间复杂度 O(1)
         */
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        auto p1 = headA, p2 = headB;
        while (p1 != p2) {
            p1 = p1 == nullptr ? headB : p1->next;
            p2 = p2 == nullptr ? headA : p2->next;
        }
        return p1;
    }

private:
    int listLength(ListNode *head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
};