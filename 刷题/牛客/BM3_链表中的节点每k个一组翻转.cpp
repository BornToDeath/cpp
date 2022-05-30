//
// Created by lixiaoqing on 2022/5/12.
//

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) {
            return head;
        }
        auto newHead = new ListNode(-1);
        newHead->next = head;
        auto tail = newHead;
        int count = 0;
        while (head) {
            ++count;
            if (count == k) {
                // 翻转链表
                auto cur = tail->next;
                for (int i = 1; i < count; ++i) {
                    auto next = cur->next;
                    cur->next = next->next;
                    next->next = tail->next;
                    tail->next = next;
                }
                tail = cur;
                head = cur->next;
                count = 0;
            } else {
                head = head->next;
            }
        }
        return newHead->next;
    }
};

int main() {
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next->next->next->next->next->next = new ListNode(11);

    auto newHead = Solution().reverseKGroup(head, 4);
    while (newHead) {
        std::cout << newHead->val << ", ";
        newHead = newHead->next;
    }
    std::cout << std::endl;
    return 0;
}