//
// Created by lixiaoqing on 2022/5/7.
//

#ifndef LISTNODE_H
#define LISTNODE_H

class ListNode {
public:
    ListNode(int val) : val(val), next(nullptr) {}

private:
    int val;
    ListNode *next;
};

#endif //LISTNODE_H
