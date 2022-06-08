//
// Created by lixiaoqing on 2022/6/8.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include "ListNode.h"

ListNode *constructList(const std::vector<int> &arr) {
    if (arr.empty()) {
        return nullptr;
    }
    auto head = new ListNode(arr[0]);
    auto node = head;
    for (int i = 1; i < arr.size(); ++i) {
        node->next = new ListNode(arr[i]);
        node = node->next;
    }
    return head;
}

void print(ListNode *head) {
    while (head) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << std::endl;
}

void print(std::vector<ListNode *> &arr) {
    for (auto node: arr) {
        std::cout << node->val << ", ";
    }
    std::cout << std::endl;
}


class Solution {
public:
    void reorderList(ListNode *head) {
        /**
         * 方法1：空间复杂度O(n)
         */
//        if (head == nullptr) {
//            return;
//        }
//        std::vector<ListNode *> nodes;
//        auto node = head;
//        while (node) {
//            nodes.emplace_back(node);
//            node = node->next;
//        }
////        print(nodes);
//        node = head;
//        while (!nodes.empty()) {
//            nodes.erase(nodes.begin());
//            if (!nodes.empty()) {
//                auto next = node->next;
//                node->next = nodes.back();
//                nodes.back()->next = next;
//                node = next;
//                nodes.pop_back();
//            }
////            std::cout << "node=" << node->val << std::endl;
//        }
//        // 最后一个元素的next要置为nullptr
//        node->next = nullptr;

        /**
         * 方法2：空间复杂度O(1)
         */
        if (head == nullptr) {
            return;
        }
        // 找中间结点
        auto slow = head, fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto after = slow->next;
        slow->next = nullptr;
//        print(head);
        // 将中间结点至末尾的结点反转
        ListNode *pre = nullptr;
        while (after) {
            auto next = after->next;
            after->next = pre;
            pre = after;
            after = next;
        }
//        print(pre);
        // 将 head 和 pre 两个链表交叉合并
        auto node = head;
        while (node && pre) {
            auto next1 = node->next;
            auto next2 = pre->next;
            node->next = pre;
            pre->next = next1;
            node = next1;
            pre = next2;
        }
    }
};

int main() {
    auto head = constructList({1, 2, 3, 4, 5, 6, 7});
    print(head);
    Solution().reorderList(head);
    print(head);
    return 0;
}