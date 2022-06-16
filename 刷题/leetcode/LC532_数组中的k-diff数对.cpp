//
// Created by lixiaoqing on 2022/6/16.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        /**
         * 方法1：两个 std::set
         */
//        std::unordered_set<int> set;
//        std::unordered_set<int> resSet;
//        for (auto num: nums) {
//            if (set.find(num + k) != set.end() && resSet.find(num) == resSet.end()) {
//                resSet.emplace(num);
//            }
//            if (set.find(num - k) != set.end() && resSet.find(num - k) == resSet.end()) {
//                resSet.emplace(num - k);
//            }
//            set.emplace(num);
//        }
//        return resSet.size();

        /**
         * 方法2：双指针
         */
        std::sort(nums.begin(), nums.end());
        int count = 0, len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            while (j < len && nums[j] - nums[i] < k) {
                ++j;
            }
            if (j < len && nums[j] - nums[i] == k) {
                ++count;
            }
        }
        return count;

        /**
         * 方法3：递归，不AC，时间超限
         */
//        std::sort(nums.begin(), nums.end());
//        std::unordered_set<int> set;
//        findPairs(nums, k, 0, nums.size() - 1, set);
//        return set.size();
    }

private:
    void findPairs(std::vector<int> &nums, int k, int i, int j, std::unordered_set<int> &set) {
        if (i >= j) {
            return;
        }
        if (nums[j] - nums[i] == k && set.find(nums[i]) == set.end()) {
            set.emplace(nums[i]);
        }
        findPairs(nums, k, i + 1, j, set);
        findPairs(nums, k, i, j - 1, set);
    }
};

int main() {
    std::vector<int> arr = {3, 1, 4, 1, 5};
//    std::vector<int> arr = {1, 3, 1, 5, 4};
    int k = 2;
    std::cout << Solution().findPairs(arr, k) << std::endl;
    return 0;
}