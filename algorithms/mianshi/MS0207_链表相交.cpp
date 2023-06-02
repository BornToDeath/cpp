//
// Created by lixiaoqing on 2023/6/2.
//

#include "ListNode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        auto node1 = headA, node2 = headB;
        while (node1 != node2) {
            node1 = node1 == nullptr ? headB : node1->next;
            node2 = node2 == nullptr ? headA : node2->next;
        }
        return node1;
    }
};