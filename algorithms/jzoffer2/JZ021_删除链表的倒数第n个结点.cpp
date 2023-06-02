//
// Created by lixiaoqing on 2023/6/2.
//

#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        /*
         * 方法1: 先计算长度, 再删除
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
//        auto dummyHead = new ListNode(-1);
//        dummyHead->next = head;
//        int length = 0;
//        while (head) {
//            ++length;
//            head = head->next;
//        }
//        auto cur = dummyHead;
//        for (int i = 0; i < length - n; ++i) {
//            cur = cur->next;
//        }
//        auto next = cur->next->next;
//        cur->next = next;
//        auto ans = dummyHead->next;
//        delete dummyHead;
//        return ans;

        /*
         * 方法2: 双指针
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        if (head == nullptr) {
            return head;
        }
        ListNode *fast = head, *slow = head, *pre = nullptr;
        while (n > 0) {
            fast = fast->next;
            --n;
        }
        while (fast) {
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (pre) {
            pre->next = slow->next;
        } else {
            head = head->next;
        }
        return head;
    }
};

int main() {
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    auto ans = Solution().removeNthFromEnd(head, 1);
    while (ans) {
        std::cout << ans->val << ", ";
        ans = ans->next;
    }
    std::cout << std::endl;
    return 0;
}