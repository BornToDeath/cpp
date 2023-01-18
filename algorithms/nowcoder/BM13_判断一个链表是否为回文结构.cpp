//
// Created by lixiaoqing on 2022/5/7.
//

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

#include <vector>
#include "ListNode.h"

class Solution {
public:
    /**
     *
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode *head) {
        if (!head) {
            return false;
        }
        std::vector<int> vals;
        while (head != nullptr) {
            vals.emplace_back(head->val);
            head = head->next;
        }
        auto len = vals.size();
        for (int i = 0; i < len; ++i) {
            if (vals[i] != vals[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};