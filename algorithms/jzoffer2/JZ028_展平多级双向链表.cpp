//
// Created by lixiaoqing on 2023/4/24.
//

#include <iostream>
#include <stack>

// Definition for a Node.
class Node {
public:
    Node(int val) : val(val), prev(nullptr), next(nullptr), child(nullptr) {}

public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:
    Node *flatten(Node *head) {
        /*
         * dfs
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
        std::stack<Node *> _stack;
        Node *cur = head, *pre = nullptr;
        while (cur || !_stack.empty()) {
            if (cur == nullptr) {
                cur = _stack.top();
                _stack.pop();
                cur->prev = pre;
                pre->next = cur;
            }
            if (cur->child) {
                if (cur->next) {
                    _stack.push(cur->next);
                }
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = nullptr;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};

int main() {
    auto l1 = new Node(1);
    l1->next = new Node(2);
    l1->next->prev = l1;
    l1->next->next = new Node(3);
    l1->next->next->prev = l1->next;
    l1->next->next->next = new Node(4);
    l1->next->next->next->prev = l1->next->next;
    l1->next->next->next->next = new Node(5);
    l1->next->next->next->next->prev = l1->next->next->next;
    l1->next->next->next->next->next = new Node(6);
    l1->next->next->next->next->next->prev = l1->next->next->next->next;

    auto l2 = new Node(7);
    l2->next = new Node(8);
    l2->next->prev = l2;
    l2->next->next = new Node(9);
    l2->next->next->prev = l2->next;
    l2->next->next->next = new Node(10);
    l2->next->next->next->prev = l2->next->next;

    l1->next->next->child = l2;

    auto l3 = new Node(11);
    l3->next = new Node(12);
    l3->next->prev = l3;

    l2->next->child = l3;

    auto ans = Solution().flatten(l1);
    while (ans) {
        std::cout << ans->val << ", ";
        ans = ans->next;
    }
    std::cout << std::endl;
    return 0;
}