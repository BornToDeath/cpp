//
// Created by lixiaoqing on 2022/6/21.
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
         * 方法1：先计算长度，然后长链表先偏移两者差值个长度，这样两个链表剩余长度相同，
         * 然后两个链表再一起向后移动，直至都为空或相等
         * 时间复杂度O(m+n)，空间复杂度O(1)
         */
//        int lenA = getLengthOfListNode(headA);
//        int lenB = getLengthOfListNode(headB);
//        if (lenA == 0 || lenB == 0) {
//            return nullptr;
//        }
//        if (lenA > lenB) {
//            for (int i = 0; i < std::abs(lenA - lenB); ++i) {
//                headA = headA->next;
//            }
//        } else if (lenA < lenB) {
//            for (int i = 0; i < std::abs(lenA - lenB); ++i) {
//                headB = headB->next;
//            }
//        }
//        while (headA && headB && headA != headB) {
//            headA = headA->next;
//            headB = headB->next;
//        }
//        return headA;

        /**
         * 方法2：双指针。链表A和链表B都偏移两个链表长度总和个长度，直至两者都为空或相等
         * 时间复杂度O(m+n)，空间复杂度O(1)
         */
        auto nodeA = headA;
        auto nodeB = headB;
        while (nodeA || nodeB) {
            if (nodeA && nodeB && nodeA == nodeB) {
                return nodeA;
            }
            if (nodeA == nullptr) {
                nodeA = headB;
            } else {
                nodeA = nodeA->next;
            }
            if (nodeB == nullptr) {
                nodeB = headA;
            } else {
                nodeB = nodeB->next;
            }
        }
        return nullptr;
    }

private:
    int getLengthOfListNode(ListNode *head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
};