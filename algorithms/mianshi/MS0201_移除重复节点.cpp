//
// Created by lixiaoqing on 2023/6/5.
//

#include <unordered_set>
#include "ListNode.h"

class Solution {
public:
    ListNode *removeDuplicateNodes(ListNode *head) {
        /*
         * 方法1: 哈希表
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
        if (head == nullptr) {
            return head;
        }
        std::unordered_set<int> s;
        s.insert(head->val);
        auto pre = head, cur = head->next;
        while (cur) {
            if (s.count(cur->val) != 0) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            } else {
                s.insert(cur->val);
                pre = cur;
                cur = cur->next;
            }
        }
        return head;

        /*
         * 方法2: 双重循环
         * 时间复杂度 O(n^2) , 空间复杂度 O(1)
         */
//        if (head == nullptr) {
//            return head;
//        }
//        auto cur = head;
//        while (cur) {
//            auto temp = cur;
//            while (temp->next) {
//                if (temp->next->val == cur->val) {
//                    auto next = temp->next;
//                    temp->next = next->next;
//                    delete next;
//                } else {
//                    temp = temp->next;
//                }
//            }
//            cur = cur->next;
//        }
//        return head;
    }
};