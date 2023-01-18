//
// Created by lixiaoqing on 2022/10/18.
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        auto head = new ListNode(-1);
        auto cur = head;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        if (pHead1) {
            cur->next = pHead1;
        }
        if (pHead2) {
            cur->next = pHead2;
        }
        return head->next;
    }
};
