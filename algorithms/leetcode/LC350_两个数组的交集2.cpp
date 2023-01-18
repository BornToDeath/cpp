//
// Created by lixiaoqing on 2022/9/5.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        /**
         * 方法1：哈希表
         * 时间复杂度 O(m + n) ，空间复杂度 O(min(m, n))
         */
        if (nums1.empty() || nums2.empty()) {
            return {};
        }
        if (nums1.size() > nums2.size()) {
            intersect(nums2, nums1);
        }
        std::vector<int> ans;
        std::unordered_map<int, int> map;
        for (auto num: nums1) {
            ++map[num];
        }
        for (auto num: nums2) {
            if (map[num] > 0) {
                ans.emplace_back(num);
                --map[num];
            }
        }
        return ans;

        /**
         * 方法2：如果两个数组是有序的，则可以使用双指针法，此时
         * 时间复杂度 O(m + n) ，空间复杂度 O(1)
         */
    }
};

int main() {
    std::unordered_map<int, int> map;
    map[1] = 1;
    std::cout << map[2] << std::endl;
    return 0;
}