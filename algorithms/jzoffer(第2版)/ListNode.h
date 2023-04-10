//
// Created by lixiaoqing on 2022/6/15.
//

#ifndef ALGORITHMS_LISTNODE_H
#define ALGORITHMS_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //ALGORITHMS_LISTNODE_H
