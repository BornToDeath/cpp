//
// Created by lixiaoqing on 2022/6/24.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        /**
         * 方法1：先计算链表的长度，然后再计算要删除节点的位置
         */
//        int len = lengthOfListNode(head);
//        if (n <= 0 || len < n) {
//            return head;
//        }
//        auto newHead = new ListNode(-1);
//        newHead->next = head;
//        auto temp = newHead;
//        for (int i = 0; i < len - n; ++i) {
//            temp = temp->next;
//        }
//        temp->next = temp->next->next;
//        return newHead->next;

        /**
         * 方法2：双指针。快指针比满指针前进 n 个节点
         */
        if (head == nullptr || n <= 0) {
            return head;
        }
        ListNode *fast = head, *slow = head, *pre = nullptr;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        if (pre == nullptr) {
            head = head->next;
        } else {
            pre->next = pre->next->next;
        }
        return head;
    }

private:
    int lengthOfListNode(ListNode *head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
};

int main() {
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    auto ans = Solution().removeNthFromEnd(head, 2);
    while (ans) {
        std::cout << ans->val << ", ";
        ans = ans->next;
    }
    std::cout << std::endl;
    return 0;
}