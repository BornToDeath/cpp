//
// Created by lixiaoqing on 2022/10/19.
//

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

#include "ListNode.h"

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *FindKthToTail(ListNode *pHead, int k) {
        /**
         * 方法1：先计算链表长度，再向后偏移
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        auto node = pHead;
//        int len = 0;
//        while (node) {
//            ++len;
//            node = node->next;
//        }
//        if (k > len) {
//            return nullptr;
//        }
//        for (int i = 0; i < len - k; ++i) {
//            pHead = pHead->next;
//        }
//        return pHead;

        /**
         * 方法2：快慢指针：快指针先走 k 步，然后快慢指针同时走，直到快指针为空
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        auto fast = pHead;
        int step = 0;
        for (; step < k && fast; ++step) {
            fast = fast->next;
        }
        if (step < k) {
            return nullptr;
        }
        auto slow = pHead;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};