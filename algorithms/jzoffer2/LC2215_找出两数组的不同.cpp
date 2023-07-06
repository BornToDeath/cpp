//
// Created by lixiaoqing on 2023/7/6.
//

#include <vector>
#include <unordered_set>

using std::vector;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        std::vector<std::vector<int>> ans(2, std::vector<int>());
        std::unordered_set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end());
        for (auto n: set1) {
            if (set2.count(n) == 0) {
                ans.front().push_back(n);
            }
        }
        for (auto n: set2) {
            if (set1.count(n) == 0) {
                ans.back().push_back(n);
            }
        }
        return ans;
    }
};