//
// Created by lixiaoqing on 2022/2/23.
//

#include <iostream>

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};

void printList(RandomListNode *head) {
    auto temp = head;
    while (head != nullptr) {
        std::cout << head->label << ", ";
        head = head->next;
    }
    while (temp != nullptr) {
        if (temp->random == nullptr) {
            std::cout << "#, ";
        } else {
            std::cout << temp->random->label << ", ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }

        // 1. 先复制一份
        RandomListNode *node = pHead;
        RandomListNode *pre = node;
        while (node != nullptr) {
            auto temp = new RandomListNode(node->label);
            temp->next = node->next;
            pre->next = temp;
            node = temp->next;
            pre = node;
        }

        // 2. 再构造random指针
        node = pHead;
        while (node != nullptr) {
            auto temp = node->next;
            if (node->random) {
                temp->random = node->random->next;
            }
            node = temp->next;
        }

        // 3. 再拆分新旧链表
        auto newHead = pHead->next;
        node = pHead;
        while (node != nullptr) {
            auto temp = node->next;
            node->next = temp->next;
            if (temp->next) {
                temp->next = temp->next->next;
            }
            node = node->next;
        }

        return newHead;
    }
};

int main() {
    RandomListNode *head = new RandomListNode(1);
    auto node2 = head->next = new RandomListNode(2);
    auto node3 = head->next->next = new RandomListNode(3);
    auto node4 = head->next->next->next = new RandomListNode(4);
    auto node5 = head->next->next->next->next = new RandomListNode(5);
    head->random = node3;
    node2->random = node5;
    node4->random = node2;

    Solution solution;
    auto newHead = solution.Clone(head);

    printList(head);
    printList(newHead);

    return 0;
}