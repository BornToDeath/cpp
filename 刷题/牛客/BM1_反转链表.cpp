//
// Created by lixiaoqing on 2022/10/18.
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode *ReverseList(ListNode *pHead) {
        ListNode *pre = nullptr, *next = nullptr;
        while (pHead) {
            next = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = next;
        }
        return pre;
    }
};
