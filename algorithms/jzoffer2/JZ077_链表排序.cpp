//
// Created by lixiaoqing on 2023/5/30.
//

#include <iostream>
#include <vector>
#include <map>
#include "ListNode.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        /*
         * 方法1: 借助 map
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
//        std::multimap<int, ListNode *> listMap;
//        while (head) {
//            listMap.insert({head->val, head});
//            head = head->next;
//        }
//        ListNode *newHead = nullptr, *cur = nullptr;
//        for (auto &pair: listMap) {
//            if (newHead == nullptr) {
//                newHead = cur = pair.second;
//            } else {
//                cur->next = pair.second;
//                cur = cur->next;
//            }
//        }
//        if (cur) {
//            cur->next = nullptr;
//        }
//        return newHead;

        /*
         * 方法2: 借助归并排序的思想, 自顶向下
         * 时间复杂度 O(nlogn) , 空间复杂度 O(logn)
         */
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//        auto fast = head, slow = head;
//        ListNode *pre = nullptr;
//        while (fast && fast->next) {
//            fast = fast->next->next;
//            pre = slow;
//            slow = slow->next;
//        }
//        if (pre) {
//            pre->next = nullptr;
//        }
//        auto head1 = sortList(head);
//        auto head2 = sortList(slow);
//        return merge(head1, head2);

        /*
         * 方法3: 归并排序, 自底向上
         * 时间复杂度 O(nlogn) , 空间复杂度 O(1)
         */
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int length = 0;
        auto node = head;
        while (node) {
            ++length;
            node = node->next;
        }
        auto dummyHead = new ListNode(-1);
        dummyHead->next = head;
        for (int len = 1; len < length; len <<= 1) {
            auto pre = dummyHead, cur = pre->next;
            while (cur) {
                // 第一个链表
                auto head1 = cur;
                for (int i = 1; i < len && cur->next; ++i) {
                    cur = cur->next;
                }
                // 第二个链表
                auto head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for (int i = 1; i < len && cur && cur->next; ++i) {
                    cur = cur->next;
                }
                ListNode *next = nullptr;
                if (cur) {
                    next = cur->next;
                    cur->next = nullptr;
                }
                // 合并
                auto temp = merge(head1, head2);
                pre->next = temp;
                while (pre && pre->next) {
                    pre = pre->next;
                }
                cur = next;
            }
        }
        return dummyHead->next;
    }

private:
    ListNode *merge(ListNode *head1, ListNode *head2) {
        auto newHead = new ListNode(-1);
        auto cur = newHead;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                cur->next = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        if (head1) {
            cur->next = head1;
        }
        if (head2) {
            cur->next = head2;
        }
        return newHead->next;
    }
};

ListNode *constructList(const std::vector<int> &nums) {
    if (nums.empty()) {
        return nullptr;
    }
    auto head = new ListNode(nums.front());
    auto cur = head;
    for (int i = 1; i < nums.size(); ++i) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}

int main() {
    auto head = constructList({-1, 5, 3, 4, 0});
    head = constructList({5, 4, 3, 2, 1});
    auto newHead = Solution().sortList(head);
    while (newHead) {
        std::cout << newHead->val << ", ";
        newHead = newHead->next;
    }
    std::cout << std::endl;
    return 0;
}