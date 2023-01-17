//
// Created by lixiaoqing on 2023/1/16.
//

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        /**
         * 方法1：哈希表
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        std::unordered_map<int, int> _map;
//        for (int i = 0; i < nums.size(); ++i) {
//            if (_map.count(nums[i]) && i - _map[nums[i]] <= k) {
//                return true;
//            }
//            _map[nums[i]] = i;
//        }
//        return false;

        /**
         * 方法2：滑动窗口，记录窗口内的元素
         * 时间复杂度 O(n) ，空间复杂度 O(k)
         */
        std::unordered_set<int> _set;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                _set.erase(nums[i - k - 1]);
            }
            if (_set.count(nums[i])) {
                return true;
            }
            _set.insert(nums[i]);
        }
        return false;
    }
};