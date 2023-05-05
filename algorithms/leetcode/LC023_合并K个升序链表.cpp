//
// Created by lixiaoqing on 2023/5/5.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <vector>
#include <queue>
#include "ListNode.h"

using std::vector;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        /*
         * 方法1: 自定义 sort
         * 时间复杂度 O(nlogn) , 空间复杂度 O(n) , 其中 n 是 k 个链表的总长度
         */
//        std::vector<ListNode *> v;
//        for (auto list: lists) {
//            while (list) {
//                v.emplace_back(list);
//                list = list->next;
//            }
//        }
//        std::sort(v.begin(), v.end(), [](ListNode *node1, ListNode *node2) { return node1->val < node2->val; });
//        auto head = new ListNode(-1);
//        auto cur = head;
//        for (auto node: v) {
//            cur->next = node;
//            cur = cur->next;
//        }
//        cur->next = nullptr;
//        return head->next;

        /*
         * 方法2: 逐个比较
         * 时间复杂度 O(nk) , 空间复杂度 O(1) , 其中 n 是 k 个链表的平均长度
         */
//        auto head = new ListNode(-1);
//        auto cur = head;
//        while (true) {
//            int pos = -1;
//            for (int i = 0; i < lists.size(); ++i) {
//                auto temp = lists.at(i);
//                if (temp && (pos == -1 || lists.at(pos)->val > temp->val)) {
//                    pos = i;
//                }
//            }
//            if (pos == -1) {
//                break;
//            }
//            cur->next = lists[pos];
//            cur = cur->next;
//            lists[pos] = lists[pos]->next;
//        }
//        return head->next;

        /*
         * 方法3: 优先队列, 自定义排序规则
         * 时间复杂度
         */
        class comp {
        public:
            // 小顶堆
            bool operator()(ListNode *node1, ListNode *node2) {
                return node1->val > node2->val;
            }
        };
        std::priority_queue<ListNode *, std::vector<ListNode *>, comp> pq;
        for (auto list: lists) {
            while (list) {
                pq.push(list);
                list = list->next;
            }
        }
        auto head = new ListNode(-1);
        auto cur = head;
        while (!pq.empty()) {
            cur->next = pq.top();
            cur = cur->next;
            pq.pop();
        }
        cur->next = nullptr;
        return head->next;
    }
};

ListNode *constructList(const std::vector<int> &arr) {
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
    lists.emplace_back(constructList({1, 4, 5}));
    lists.emplace_back(constructList({1, 3, 4}));
    lists.emplace_back(constructList({2, 6}));
    auto head = Solution().mergeKLists(lists);
    while (head) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << std::endl;
    return 0;
}