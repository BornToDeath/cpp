//
// Created by lixiaoqing on 2023/4/11.
//

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /*
         * 方法1: 快慢指针
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        auto fast = head, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        while (slow != head) {
            slow = slow->next;
            head = head->next;
        }
        return head;

        /*
         * 方法2: 哈希表
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
        //        std::unordered_set<ListNode*> _set;
        //        while (head) {
        //            if (_set.count(head)) {
        //                return head;
        //            }
        //            _set.insert(head);
        //            head = head->next;
        //        }
        //        return nullptr;
    }
};