//
// Created by lixiaoqing on 2023/6/2.
//

#include "ListNode.h"

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *fast = head, *slow = head, *pre = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            auto next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        if (fast) {
            slow = slow->next;
        }
        while (slow && pre) {
            if (slow->val != pre->val) {
                return false;
            }
            slow = slow->next;
            pre = pre->next;
        }
        return true;
    }
};