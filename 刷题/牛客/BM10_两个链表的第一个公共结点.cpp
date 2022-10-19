//
// Created by lixiaoqing on 2022/10/19.
//

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

#include <unordered_set>
#include "ListNode.h"

class Solution {
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        /**
         * 方法1：先计算链表长度，然后长链表先向后移动，然后两个链表同时向后移动直至相同
         * 时间复杂度 O(n + m) ，空间复杂度 O(1)
         */
//        auto getListLength = [](ListNode *head) -> int {
//            int len = 0;
//            while (head) {
//                ++len;
//                head = head->next;
//            }
//            return len;
//        };
//        auto len1 = getListLength(pHead1);
//        auto len2 = getListLength(pHead2);
//        if (len1 > len2) {
//            for (int i = 0; i < len1 - len2; ++i) {
//                pHead1 = pHead1->next;
//            }
//        } else {
//            for (int i = 0; i < len2 - len1; ++i) {
//                pHead2 = pHead2->next;
//            }
//        }
//        while (pHead1) {
//            if (pHead1 == pHead2) {
//                return pHead1;
//            }
//            pHead1 = pHead1->next;
//            pHead2 = pHead2->next;
//        }
//        return nullptr;

        /**
         * 方法2：借助哈希表
         * 时间复杂度 O(n + m) ，空间复杂度 O(max(m, n))
         */
        std::unordered_set < ListNode * > _set;
        while (pHead1) {
            _set.insert(pHead1);
            pHead1 = pHead1->next;
        }
        while (pHead2) {
            if (_set.find(pHead2) != _set.end()) {
                return pHead2;
            }
            pHead2 = pHead2->next;
        }
        return nullptr;

    }
};
