//
// Created by lixiaoqing on 2022/10/19.
//

#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead) {
        /**
         * 方法1：快慢指针
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        auto slow = pHead, fast = pHead;
//        while (fast && fast->next) {
//            fast = fast->next->next;
//            slow = slow->next;
//            if (slow == fast) {
//                break;
//            }
//        }
//
//        if (fast == nullptr || fast->next == nullptr) {
//            return nullptr;
//        }
//
//        slow = pHead;
//        while (slow != fast) {
//            slow = slow->next;
//            fast = fast->next;
//        }
//        return slow;

        /**
         * 方法2：哈希表
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
        std::unordered_set<ListNode *> _set;
        while (pHead) {
            if (_set.find(pHead) != _set.end()) {
                return pHead;
            }
            _set.insert(pHead);
            pHead = pHead->next;
        }
        return nullptr;
    }
};