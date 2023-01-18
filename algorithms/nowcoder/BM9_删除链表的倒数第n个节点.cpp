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
     * @param n int整型
     * @return ListNode类
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // 计算链表长度
        int len = 0;
        auto node = head;
        while (node) {
            ++len;
            node = node->next;
        }
        // 删除节点
        auto newHead = new ListNode(-1);
        newHead->next = head;
        node = newHead;
        for (int i = 0; i < len - n; ++i) {
            node = node->next;
        }
        auto temp = node->next;
        node->next = temp->next;
        delete temp;
        temp = newHead;
        newHead = newHead->next;
        delete temp;
        return newHead;
    }
};

int main() {
    auto root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    print(root);

    auto res = Solution().removeNthFromEnd(root, 5);
    print(res);

    return 0;
}