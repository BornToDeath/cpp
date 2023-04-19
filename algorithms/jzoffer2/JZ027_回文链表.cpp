//
// Created by lixiaoqing on 2023/4/19.
//

#include <iostream>
#include <vector>
#include "ListNode.h"

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        /*
         * 方法: 反转前半部分链表
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        ListNode *slow = head, *fast = head, *pre = nullptr;
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
    std::vector<int> nums = {1, 2, 2, 1};
    nums = {1};
    auto head = constructList(nums);
    std::cout << Solution().isPalindrome(head) << std::endl;
    return 0;
}