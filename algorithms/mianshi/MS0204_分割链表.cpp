//
// Created by lixiaoqing on 2023/6/6.
//

#include <vector>
#include <iostream>
#include "ListNode.h"

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        /*
         * 方法1: 设置两个虚节点
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
//        auto h1 = new ListNode(-1), h2 = new ListNode(-1);
//        auto cur1 = h1, cur2 = h2;
//        while (head) {
//            if (head->val < x) {
//                cur1->next = head;
//                cur1 = cur1->next;
//            } else {
//                cur2->next = head;
//                cur2 = cur2->next;
//            }
//            head = head->next;
//        }
//        cur1->next = h2->next;
//        cur2->next = nullptr;
//        auto ans = h1->next;
//        delete h1;
//        delete h2;
//        return ans;

        /*
         * 方法2: 不用虚拟节点
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        ListNode *h1 = nullptr, *h2 = nullptr, *n1 = nullptr, *n2 = nullptr;
        while (head) {
            if (head->val < x) {
                if (h1 == nullptr) {
                    h1 = n1 = head;
                } else {
                    n1->next = head;
                    n1 = n1->next;
                }
            } else {
                if (h2 == nullptr) {
                    h2 = n2 = head;
                } else {
                    n2->next = head;
                    n2 = n2->next;
                }
            }
            head = head->next;
        }
        if (n1) {
            n1->next = h2;
        } else {
            h1 = h2;
        }
        if (n2) {
            n2->next = nullptr;
        }
        return h1;
    }
};

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

int main() {
    std::vector<int> nums = {1, 4, 3, 2, 5, 2};
    auto head = constructList(nums);
    auto ans = Solution().partition(head, 3);
    while (ans) {
        std::cout << ans->val << ", ";
        ans = ans->next;
    }
    std::cout << std::endl;
}