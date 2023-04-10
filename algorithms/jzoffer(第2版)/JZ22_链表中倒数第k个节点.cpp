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
    ListNode *getKthFromEnd(ListNode *head, int k) {
        /**
         * 方法1：先计算链表长度，再从前往后遍历
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        auto len = listLength(head);
//        if (len < k) {
//            return nullptr;
//        }
//        for (int i = 0; i < len - k; ++i) {
//            head = head->next;
//        }
//        return head;

        /**
         * 方法2：双指针
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        auto fast = head;
        for (int i = 0; i < k; ++i) {
            if (fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;
        }
        while (fast) {
            head = head->next;
            fast = fast->next;
        }
        return head;
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