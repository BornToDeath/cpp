//
// Created by lixiaoqing on 2023/6/6.
//

#include "ListNode.h"

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        auto next = node->next;
        node->next = next->next;
        delete next;
    }
};