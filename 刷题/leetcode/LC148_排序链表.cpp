//
// Created by lixiaoqing on 2022/7/4.
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
#include <map>
#include "ListNode.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        /**
         * 方法1：借助 std::multimap
         */
//        std::multimap<int, ListNode *> map;
//        auto node = head;
//        while (node) {
//            map.insert({node->val, node});
//            node = node->next;
//        }
//        auto newHead = new ListNode(-1);
//        node = newHead;
//        for (auto &ele: map) {
//            node->next = ele.second;
//            node = node->next;
//        }
//        node->next = nullptr;
//        return newHead->next;

        /**
         * 方法2：借助归并排序的思想
         * 时间复杂度O(nlogn)，空间复杂度O(1)
         */
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 精髓：使用快慢指针将单个链表分割为两个链表，然后分别归并
        ListNode *slow = head, *fast = head, *pre = nullptr;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (pre) {
            pre->next = nullptr;
        }
        auto left = sortList(head);
        auto right = sortList(slow);
        return merge_sort(left, right);
    }

private:

    ListNode *merge_sort(ListNode *head1, ListNode *head2) {
        auto newHead = new ListNode(-1);
        auto node = newHead;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                node->next = head1;
                head1 = head1->next;
            } else {
                node->next = head2;
                head2 = head2->next;
            }
            node = node->next;
        }
        if (head1) {
            node->next = head1;
        }
        if (head2) {
            node->next = head2;
        }
        return newHead->next;
    }
};

int main() {
    auto head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);
    auto ans = Solution().sortList(head);
    while (ans) {
        std::cout << ans->val << ", ";
        ans = ans->next;
    }
    std::cout << std::endl;
    return 0;
}