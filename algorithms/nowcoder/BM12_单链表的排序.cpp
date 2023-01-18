//
// Created by lixiaoqing on 2022/5/11.
//

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

#include <iostream>
#include <vector>
#include "ListNode.h"

class Solution {
public:
    /**
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode *sortInList(ListNode *head) {
        /**
         * 方法1：借助 std::sort
         */
//        if (!head) {
//            return nullptr;
//        }
//        std::vector<ListNode *> nodes;
//        while (head) {
//            nodes.push_back(head);
//            head = head->next;
//        }
//        std::sort(nodes.begin(), nodes.end(), [](ListNode *node1, ListNode *node2) {
//            return node1->val < node2->val;
//        });
//        auto newHead = new ListNode(-1);
//        auto temp = newHead;
//        for (auto node: nodes) {
//            temp->next = node;
//            temp = node;
//        }
//        temp->next = nullptr;
//        return newHead->next;

        /**
         * 方法2：插入排序
         */
//        auto newHead = new ListNode(INT_MIN);
//        while (head) {
//            auto node = head;
//            head = head->next;
//            node->next = nullptr;
//            auto temp = newHead;
//            while (temp) {
//                if (temp->next && temp->next->val < node->val) {
//                    temp = temp->next;
//                } else {
//                    node->next = temp->next;
//                    temp->next = node;
//                    break;
//                }
//            }
//        }
//        return newHead->next;

        /**
         * 方法3：归并排序
         */
        if (!head || !head->next) {
            return head;
        }
        auto fast = head;
        auto slow = head;
        ListNode *pre = nullptr;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (pre) {
            pre->next = nullptr;
        }
        auto left = sortInList(head);
        auto right = sortInList(slow);
        // 合并两个有序链表
        return merge(left, right);
    }

private:
    ListNode *merge(ListNode *list1, ListNode *list2) {
        auto head = new ListNode(-1);
        auto node = head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        if (list1) {
            node->next = list1;
        }
        if (list2) {
            node->next = list2;
        }
        return head->next;
    }
};

int main() {
    auto head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(4);
    auto newHead = Solution().sortInList(head);
    while (newHead) {
        std::cout << newHead->val << ", ";
        newHead = newHead->next;
    }
    std::cout << std::endl;
    return 0;
}