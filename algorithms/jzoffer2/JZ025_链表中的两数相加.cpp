//
// Created by lixiaoqing on 2023/4/21.
//

#include <iostream>
#include <vector>
#include <stack>
#include "ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        /*
         * 方法1: 先反转链表再相加
         * 时间复杂度 O(m + n) , 空间复杂度 O(1)
         */
//        l1 = reverseList(l1);
//        l2 = reverseList(l2);
//        ListNode *head = nullptr, *cur = head;
//        int carry = 0;
//        while (l1 || l2 || carry) {
//            int sum = carry;
//            if (l1) {
//                sum += l1->val;
//                l1 = l1->next;
//            }
//            if (l2) {
//                sum += l2->val;
//                l2 = l2->next;
//            }
//            carry = sum / 10;
//            sum %= 10;
//            if (cur) {
//                cur->next = new ListNode(sum);
//                cur = cur->next;
//            } else {
//                head = cur = new ListNode(sum);
//            }
//        }
//        return reverseList(head);

        /*
         * 方法2: 借助 std::stack
         * 时间复杂度 O(m + n) , 空间复杂度 O(m + n)
         */
        std::stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        std::stack<int> ans;
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            sum %= 10;
            ans.push(sum);
        }
        ListNode *head = nullptr, *cur = nullptr;
        while (!ans.empty()) {
            if (cur) {
                cur->next = new ListNode(ans.top());
                cur = cur->next;
            } else {
                head = cur = new ListNode(ans.top());
            }
            ans.pop();
        }
        return head;
    }

private:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        while (head) {
            auto next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
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
    std::vector<int> nums1 = {7, 2, 4, 3};
    std::vector<int> nums2 = {5, 6, 4};
    auto l1 = constructList(nums1);
    auto l2 = constructList(nums2);
    auto head = Solution().addTwoNumbers(l1, l2);
    while (head) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    return 0;
}