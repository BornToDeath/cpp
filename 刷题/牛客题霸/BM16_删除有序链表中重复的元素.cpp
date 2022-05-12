//
// Created by lixiaoqing on 2022/5/12.
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

void print(ListNode *head) {
    while (head) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << std::endl;
}

ListNode *constructList(std::vector<int> arr) {
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

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *deleteDuplicates(ListNode *head) {
        auto newHead = new ListNode(-1);
        newHead->next = head;
        auto pre = newHead;
        while (head) {
            if (head->next && head->val == head->next->val) {
                auto val = head->val;
                while (head && head->val == val) {
                    head = head->next;
                }
                pre->next = head;
            } else {
                pre = head;
                head = head->next;
            }
        }
        return newHead->next;
    }
};


int main() {
    auto head = constructList({1});
    print(head);
    auto newHead = Solution().deleteDuplicates(head);
    print(newHead);
    return 0;
}
