//
// Created by lixiaoqing on 2022/7/1.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_set>
#include "ListNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /**
         * 方法1：快慢指针
         */
//        ListNode *fast = head, *slow = head;
//        while (fast && fast->next) {
//            fast = fast->next->next;
//            slow = slow->next;
//            if (fast == slow) {
//                break;
//            }
//        }
//        if (fast == nullptr || fast->next == nullptr) {
//            return nullptr;
//        }
//        while (head != fast) {
//            head = head->next;
//            fast = fast->next;
//        }
//        return head;

        /**
         * 方法2：借助哈希表
         */
        std::unordered_set<ListNode *> set;
        while (head) {
            if (set.find(head) != set.end()) {
                return head;
            }
            set.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};