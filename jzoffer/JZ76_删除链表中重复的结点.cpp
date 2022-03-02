//
// Created by lixiaoqing on 2022/3/2.
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

void printList(const ListNode *head) {
    while (head != nullptr) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode *deleteDuplication(ListNode *pHead) {
        if (pHead == nullptr || pHead->next == nullptr) {
            return pHead;
        }

        auto newHead = new ListNode(-1);
        newHead->next = pHead;

        auto pre = newHead;
        while (pre->next != nullptr) {
            auto cur = pre->next;
            int value = cur->val;
            if (cur->next != nullptr && value == cur->next->val) {
                while (cur != nullptr && value == cur->val) {
                    cur = cur->next;
                }
                pre->next = cur;
                continue;
            }
            pre = cur;
        }

        return newHead->next;
    }
};

int main() {
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    printList(head);

    Solution solution;
    auto node = solution.deleteDuplication(head);
    printList(node);

    return 0;
}