//
// Created by lixiaoqing on 2023/4/21.
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

#include "ListNode.h"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        /*
         * 方法1: 迭代
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        ListNode* pre = nullptr;
        while (head) {
            auto next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;

        /*
         * 方法2: 递归
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//        auto newHead = reverseList(head->next);
//        head->next->next = head;
//        head->next = nullptr;  // 避免形成环
//        return newHead;
    }
};