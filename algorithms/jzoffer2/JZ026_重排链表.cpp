//
// Created by lixiaoqing on 2023/4/11.
//

#include <vector>
#include <iostream>
#include "ListNode.h"

class Solution {
public:
    void reorderList(ListNode *head) {
        /*
         * 方法: 将队列拆分, 前半部分顺序, 后半部分倒序, 然后再合并链表
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }
        // 找链表中间节点
        auto fast = head, slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 反转后半部分链表
        ListNode *pre = nullptr, *cur = slow->next;
        slow->next = nullptr;
        while (cur) {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // 合并两个链表
        cur = head;
        while (cur && pre) {
            auto node1 = cur->next;
            cur->next = pre;
            cur = node1;
            node1 = pre->next;
            pre->next = cur;
            pre = node1;
        }
    }
};

ListNode *createList(const std::vector<int> &nums) {
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

void printList(ListNode *head) {
    while (head) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    auto head = createList({1, 2, 3, 4, 5, 6});
    Solution().reorderList(head);
    printList(head);
    return 0;
}