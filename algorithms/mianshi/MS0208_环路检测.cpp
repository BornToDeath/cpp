//
// Created by lixiaoqing on 2023/6/6.
//

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto fast = head, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        while (fast != head) {
            fast = fast->next;
            head = head->next;
        }
        return head;
    }
};

int main() {
    auto head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    auto ans = Solution().detectCycle(head);
    std::cout << ans->val << std::endl;
    return 0;
}