//
// Created by boss on 2023/5/5.
//




#include <iostream>


/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Input: head = [1,1,1,2,3]
Output: [2,3]

Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // 1
        auto newHead = new ListNode(-1);
        newHead->next = head;

        // 2
        auto pre = newHead;
        while (head) {
            if (head->next && head->val == head->next->val) {
                auto val = head->val;
                while (head && head->val == val) {
                    auto next = head->next;
                    delete head;  // destructor
                    head = next;  // pointer to next
                }
                pre->next = head;
            } else {  // or
                pre = head;
                head = head->next;
            }
        }

        // 3. return next of virtual head
        auto temp = newHead->next;
        delete newHead;  // destructor
        return temp;
    }
};


int main() {
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);
    auto ans = Solution().deleteDuplicates(head);
    while (ans) {
        std::cout << ans->val << ", ";
        ans = ans->next;
    }
    std::cout << std::endl;
    return 0;
}













