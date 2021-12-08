//
// Created by lixiaoqing on 2021/12/8.
//

#ifndef JZOFFER_LISTNODE_H
#define JZOFFER_LISTNODE_H

class ListNode {
public:
    ListNode(int x) : val(x), next(nullptr) {
        
    }

public:
    int val;
    ListNode *next;
};

#endif //JZOFFER_LISTNODE_H
