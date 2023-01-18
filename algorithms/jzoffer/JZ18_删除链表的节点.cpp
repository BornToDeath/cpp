//
// Created by lixiaoqing on 2021/12/8.
//

#include <iostream>
#include "ListNode.h"

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param val int整型
     * @return ListNode类
     */
    ListNode *deleteNode(ListNode *head, int val) {
        if (head == nullptr) {
            return nullptr;
        }

        if (head->val == val) {
            auto node = head->next;
            head->next = nullptr;
            return node;
        }

        auto pre = head;
        auto cur = pre->next;
        while (cur != nullptr) {
            if (cur->val == val) {
                pre->next = cur->next;
                cur->next = nullptr;
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};

inline void printNode(ListNode *head) {
    while (head != nullptr) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {

    auto head = new ListNode(2);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    printNode(head);

    Solution solution;
    solution.deleteNode(head, 9);
    printNode(head);

    return 0;
}
