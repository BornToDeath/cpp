//
// Created by lixiaoqing on 2022/5/11.
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
#include <string>
#include <stack>
#include "ListNode.h"

class Solution {
public:
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode *addInList(ListNode *head1, ListNode *head2) {
        /**
         * 方法1：借助栈
         */
        std::stack<int> stack1;
        while (head1) {
            stack1.push(head1->val);
            head1 = head1->next;
        }

        std::stack<int> stack2;
        while (head2) {
            stack2.push(head2->val);
            head2 = head2->next;
        }

        auto root = new ListNode(-1);
        int carry = 0;
        while (!stack1.empty() || !stack2.empty()) {
            auto num1 = 0;
            if (!stack1.empty()) {
                num1 = stack1.top();
                stack1.pop();
            }
            auto num2 = 0;
            if (!stack2.empty()) {
                num2 = stack2.top();
                stack2.pop();
            }
            auto sum = num1 + num2 + carry;
            carry = (sum >= 10) ? 1 : 0;
            sum %= 10;
            auto node = new ListNode(sum);
            node->next = root->next;
            root->next = node;
        }
        if (carry == 1) {
            auto node = new ListNode(1);
            node->next = root->next;
            root->next = node;
        }
        return root->next;

        /**
         * 方法2：先反转链表，然后再按位相加
         */
    }
};

int main() {
    auto root1 = new ListNode(9);
    root1->next = new ListNode(3);
    root1->next->next = new ListNode(7);

    auto root2 = new ListNode(6);
    root2->next = new ListNode(3);

    auto res = Solution().addInList(root1, root2);
    while (res) {
        std::cout << res->val << ", ";
        res = res->next;
    }
    std::cout << std::endl;
    return 0;
}