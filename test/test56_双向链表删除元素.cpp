//
// Created by lixiaoqing on 2023/1/11.
//

/**
 * 鉴智机器人二面算法题
 */

#include <iostream>

struct Node {
    explicit Node(int val): val(val), pre(nullptr), next(nullptr) {

    }

    int val;
    Node* pre;
    NOde* next;
};

class Solution {
public:
    Node* deleteNode(Node* head, int target) {
        Node* pre = nullptr, *node = head;
        while (node) {
            if (node->val != target) {
                pre = node;
                node = node->next;
                continue;
            }
            if (pre == nullptr) {
                node = node->next;
                head = node;
            } else {
                pre->next = node->next;
                if (node->next) {
                    node->next->pre = pre;
                }
                node = pre->next;
            }
        }
        return head;
    }
};



int main() {
    return 0;
}