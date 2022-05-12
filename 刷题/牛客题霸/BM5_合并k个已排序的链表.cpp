//
// Created by lixiaoqing on 2022/5/12.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        /**
         * 方法1：借助 std::sort 。时间复杂度 O(nlogn) ，空间复杂度 O(n)
         */
//        std::vector<ListNode *> nodes;
//        for (auto list: lists) {
//            while (list) {
//                nodes.emplace_back(list);
//                list = list->next;
//            }
//        }
//        std::sort(nodes.begin(), nodes.end(), [](ListNode *node1, ListNode *node2) {
//            return node1->val < node2->val;
//        });
//        auto head = new ListNode(-1);
//        auto cur = head;
//        for (auto node: nodes) {
//            cur->next = node;
//            cur = cur->next;
//        }
//        return head->next;

        /**
         * 方法2：归并排序。时间复杂度O(nlogk)，空间复杂度O(logk)
         */
        return mergeSort(lists, 0, lists.size() - 1);
    }

private:
    ListNode *mergeSort(std::vector<ListNode *> &lists, int start, int end) {
        if (start > end) {
            return nullptr;
        } else if (start == end) {
            return lists[start];
        }
        auto mid = (end - start) / 2 + start;
        auto list1 = mergeSort(lists, start, mid);
        auto list2 = mergeSort(lists, mid + 1, end);
        return merge(list1, list2);
    }

    ListNode *merge(ListNode *list1, ListNode *list2) {
        auto head = new ListNode(-1);
        auto node = head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        if (list1) {
            node->next = list1;
        }
        if (list2) {
            node->next = list2;
        }
        return head->next;
    }

};