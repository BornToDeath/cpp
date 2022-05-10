//
// Created by lixiaoqing on 2022/5/10.
//

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

#include <iostream>
#include "ListNode.h"

void print(ListNode *root) {
    while (root) {
        std::cout << root->val << ", ";
        root = root->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        /**
         * 方法1：理解起来较复杂
         */
//        if (head == nullptr) {
//            return head;
//        }
//        ListNode *newHead = head;
//        ListNode *pre = nullptr;
//        ListNode *next = nullptr;
//        ListNode *reverseListTail = nullptr;
//        ListNode *node = nullptr;
//        int i = 0;
//        while (head != nullptr) {
//            ++i;
//            if (i > n) {
//                break;
//            }
//            if (i < m) {
//                pre = head;
//                head = head->next;
//                continue;
//            }
//            if (i == m) {
//                reverseListTail = head;
//                node = pre;
//            }
//            next = head->next;
//            head->next = pre;
//            pre = head;
//            head = next;
//        }
//        if (node) {
//            node->next = pre;
//        }
//        if (reverseListTail) {
//            reverseListTail->next = head;
//        }
//        if (node == nullptr) {
//            newHead = pre;
//        }
//        return newHead;

        /**
         * 方法2：引入一个额外结点
         */
        auto newHead = new ListNode(-1);
        newHead->next = head;
        auto pre = newHead;
        for (int i = 0; i < m - 1; ++i) {
            if (pre) {
                pre = pre->next;
            }
        }
        if (pre == nullptr || pre->next == nullptr) {
            return head;
        }
        auto cur = pre->next;
        // 反转
        ListNode *next;
        for (int i = m; i < n; i++) {
            next = cur->next;
            if (next == nullptr) {
                break;
            }
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return newHead->next;
    }
};

int main() {
    auto root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    print(root);

    auto res = Solution().reverseBetween(root, 1, 10);
    print(res);
    return 0;
}
