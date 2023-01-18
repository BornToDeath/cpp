//
// Created by lixiaoqing on 2022/5/31.
//

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

#include "ListNode.h"

class Remove {
public:
    bool removeNode(ListNode *pNode) {
        if (pNode == nullptr) {
            return false;
        }
        return pNode->next != nullptr;
    }
};