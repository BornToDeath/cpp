//
// Created by lixiaoqing on 2023/6/2.
//

#include <iostream>
#include <vector>
#include <map>
#include "ListNode.h"

using std::vector;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        /*
         * 方法1: n 个指针, 分别指向 n 个链表, 然后逐个后移
         */
//        if (lists.empty()) {
//            return nullptr;
//        }
//        auto dummyHead = new ListNode(-1);
//        auto cur = dummyHead;
//        while (true) {
//            int pos = -1;
//            for (int i = 0; i < lists.size(); ++i) {
//                if (lists.at(i) != nullptr && (pos == -1 || lists.at(i)->val < lists.at(pos)->val)) {
//                    pos = i;
//                }
//            }
//            if (pos == -1) {
//                break;
//            }
//            cur->next = lists.at(pos);
//            cur = cur->next;
//            lists.at(pos) = lists.at(pos)->next;
//        }
//        auto ans = dummyHead->next;
//        delete dummyHead;
//        return ans;

        /*
         * 方法2: map
         */
        std::multimap<int, ListNode *> map;
        for (auto head: lists) {
            auto cur = head;
            while (cur) {
                map.insert({cur->val, cur});
                cur = cur->next;
            }
        }
        ListNode *ans = nullptr, *cur = nullptr;
        for (auto &e: map) {
            if (cur == nullptr) {
                ans = cur = e.second;
            } else {
                cur->next = e.second;
                cur = cur->next;
            }
        }
        return ans;

        /*
         * 方法3: 归并的思想
         */
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
    std::vector<ListNode *> lists;
    lists.push_back(constructList({1, 4, 5}));
    lists.push_back(constructList({1, 3, 4}));
    lists.push_back(constructList({2, 6}));
    auto ans = Solution().mergeKLists(lists);
    while (ans) {
        std::cout << ans->val << ", ";
        ans = ans->next;
    }
    return 0;
}