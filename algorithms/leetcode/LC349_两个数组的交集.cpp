//
// Created by lixiaoqing on 2023/1/31.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        /**
         * 方法：两个哈希表
         * 时间复杂度 O(n+m) ，空间复杂度 O(n+m)
         */
        std::unordered_set<int> s1;
        for (auto num: nums1) {
            s1.insert(num);
        }
        std::unordered_set<int> s2;
        for (auto num: nums2) {
            if (s1.count(num)) {
                s2.insert(num);
            }
        }
        std::vector<int> ans(s2.begin(), s2.end());
        return ans;
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    auto ans = Solution().intersection(nums1, nums2);
    std::for_each(ans.begin(), ans.end(), [](int num) { std::cout << num << ", "; });
    std::cout << std::endl;
    return 0;
}