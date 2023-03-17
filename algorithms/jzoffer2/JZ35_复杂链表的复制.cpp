//
// Created by lixiaoqing on 2023/3/17.
//


// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        auto cur = head;
        while (cur) {
            auto node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        auto newHead = head->next;
        cur = head;
        while (cur) {
            auto node = cur->next;
            cur->next = node->next;
            if (node->next) {
                node->next = node->next->next;
            }
            cur = cur->next;
        }
        return newHead;
    }
};

1 1 2 2 3 3