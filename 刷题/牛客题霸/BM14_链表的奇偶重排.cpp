//
// Created by lixiaoqing on 2022/5/12.
//

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

#include <iostream>
#include <vector>
#include "ListNode.h"

void print(ListNode *head) {
    while (head) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << std::endl;
}

ListNode *constructList(std::vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    auto head = new ListNode(arr[0]);
    auto node = head;
    for (int i = 1; i < arr.size(); ++i) {
        node->next = new ListNode(arr[i]);
        node = node->next;
    }
    return head;
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *oddEvenList(ListNode *head) {
        /**
         * 方法1：先区分奇偶链表，然后将偶链表放置在奇链表的尾部
         */
//        if (!head || !head->next) {
//            return head;
//        }
//        auto oddListHead = new ListNode(-1);
//        auto oddNode = oddListHead;
//        auto evenListHead = new ListNode(-1);
//        auto evenNode = evenListHead;
//        int index = 0;
//        while (head) {
//            if ((++index) % 2 == 1) {
//                oddNode->next = head;
//                oddNode = oddNode->next;
//            } else {
//                evenNode->next = head;
//                evenNode = evenNode->next;
//            }
//            head = head->next;
//        }
//        evenNode->next = nullptr;
//        oddNode->next = evenListHead->next;
//        return oddListHead->next;

        /**
         * 方法2：原地操作
         */
        if (!head || !head->next) {
            return head;
        }
        auto evenHead = head->next;
        auto odd = head, even = evenHead;
        while (even && even->next) {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

int main() {
    auto head = constructList({1, 2, 3, 4, 5, 6});
    print(head);
    auto newHead = Solution().oddEvenList(head);
    print(newHead);
    return 0;
}