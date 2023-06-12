//
// Created by lixiaoqing on 2023/6/12.
//

#include "ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto dummyHead = new ListNode(-1);
        auto cur = dummyHead;
        int carry = 0;
        while (l1 || l2 || carry) {
            auto sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        auto ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }
};