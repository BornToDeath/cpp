//
// Created by lixiaoqing on 2022/6/23.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <vector>
#include "ListNode.h"

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        /**
         * 方法1：时间复杂度O(n)，空间复杂度O(n)
         */
//        std::vector<int> nums;
//        while (head) {
//            nums.emplace_back(head->val);
//            head = head->next;
//        }
//        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
//            if (nums[i] != nums[j]) {
//                return false;
//            }
//        }
//        return true;

        /**
         * 方法2：时间复杂度O(n)，空间复杂度O(1)
         */
        ListNode *fast = head, *slow = head, *pre = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            auto next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        if (fast) {
            slow = slow->next;
        }
        while (pre && slow) {
            if (pre->val != slow->val) {
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};