//
// Created by boss on 2023/4/24.
//

#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node *_next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node *insert(Node *head, int insertVal) {
        /*
         * 方法1: 一次遍历
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        auto node = new Node(insertVal);
        if (head == nullptr) {
            node->next = node;
            return node;
        }
        auto cur = head, next = head->next;
        while (head != next) {
            // 介于前后两个数中间
            if (insertVal >= cur->val && insertVal <= next->val) {
                break;
            }
            // 介于链表交界处
            if (cur->val > next->val && (insertVal >= cur->val || insertVal <= next->val)) {
                break;
            }
            cur = next;
            next = next->next;
        }
        node->next = next;
        cur->next = node;
        return head;

        /*
         * 方法2: 两次遍历，第一次先寻找链表最小值，第二次从此位置插入节点
         *   最小值的查找方法：满足 node->next->val <= node->val && node->next != head 时, node->next 就是最小节点
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
    }
};

int main() {
//    auto head = new Node(1);
//    head->next = head;
//    int insertVal = 1;

    auto head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(1);
    head->next->next->next = head;
    int insertVal = 0;

    auto ans = Solution().insert(head, insertVal);
    return 0;
}