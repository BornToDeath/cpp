//
// Created by lixiaoqing on 2022/9/14.
//

#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        // 先构建 next 指针
        auto cur = head;
        while (cur) {
            auto node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        // 再构建 random 指针
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // 再拆分链表
        auto newHead = head->next;
        cur = head;
        while (cur) {
            auto temp = cur->next;
            cur->next = temp->next;
            if (temp->next) {
                temp->next = temp->next->next;
            }
            cur = cur->next;
        }
        return newHead;
    }
};

void printList(Node* node) {
    while (node) {
        std::cout << node->val << ", ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    Node *head = new Node(1);
    auto node2 = head->next = new Node(2);
    auto node3 = head->next->next = new Node(3);
    auto node4 = head->next->next->next = new Node(4);
    auto node5 = head->next->next->next->next = new Node(5);
    head->random = node3;
    node2->random = node5;
    node4->random = node2;
    printList(head);

    auto newHead = Solution().copyRandomList(head);
    printList(newHead);

    return 0;
}