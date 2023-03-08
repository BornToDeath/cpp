//
// Created by lixiaoqing on 2023/3/8.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <vector>
#include "ListNode.h"

using std::vector;

class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        if (head == nullptr) {
            return {};
        }
        int size = 0;
        ListNode *pre = nullptr, *next = nullptr;
        while (head) {
            ++size;
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        std::vector<int> ans(size);
        for (int i = 0; i < size && pre != nullptr; ++i) {
            ans[i] = pre->val;
            pre = pre->next;
        }
        return ans;
    }
};