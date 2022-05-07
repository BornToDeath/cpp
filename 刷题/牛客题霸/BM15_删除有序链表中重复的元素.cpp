//
// Created by lixiaoqing on 2022/5/7.
//

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

#include "ListNode.h"

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *deleteDuplicates(ListNode *head) {
        auto node = head;
        while (node) {
            if (node->next && node->val == node->next->val) {
                node->next = node->next->next;
            } else {
                node = node->next;
            }
        }
        return head;
    }
};