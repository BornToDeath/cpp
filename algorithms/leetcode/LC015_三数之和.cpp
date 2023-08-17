//
// Created by lixiaoqing on 2022/6/17.
//

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> &arr) {
    for (auto num: arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

void print(std::vector<std::vector<int>> &mat) {
    for (auto &arr: mat) {
        for (auto num: arr) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        /**
         * 方法1：遍历，时间复杂度O(n^3)，不AC，时间超限
         */
//        std::vector<std::vector<int>> res;
//        int len = nums.size();
//        for (int i = 0; i < len - 2; ++i) {
//            for (int j = i + 1; j < len - 1; ++j) {
//                for (int k = j + 1; k < len; ++k) {
//                    auto sum = nums[i] + nums[j] + nums[k];
//                    if (sum == 0) {
//                        int min = std::min(nums[i], std::min(nums[j], nums[k]));
//                        int max = std::max(nums[i], std::max(nums[j], nums[k]));
//                        std::vector<int> ele = {min, sum - min - max, max};
//                        if (std::find(res.begin(), res.end(), ele) == res.end()) {
//                            res.emplace_back(ele);
//                        }
//                    }
//                }
//            }
//        }
//        return res;

        /**
         * 方法2：时间复杂度O(nlogn+n^2)，即O(n^2)
         */
//        std::vector<std::vector<int>> res;
//        std::sort(nums.begin(), nums.end());
//        int len = nums.size();
//        for (int i = 0; i < len - 1; ++i) {
//            // 第一个数需要和上一次的不同
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;
//            }
//            for (int j = i + 1, k = len - 1; j < k; ++j) {
//                // 第二个数需要和上一次的不同
//                if (j > i + 1 && nums[j] == nums[j - 1]) {
//                    continue;
//                }
//                while (j < k && nums[i] + nums[j] + nums[k] > 0) {
//                    --k;
//                }
//                if (j >= k) {
//                    break;
//                }
//                if (nums[i] + nums[j] + nums[k] == 0) {
//                    res.push_back({nums[i], nums[j], nums[k]});
//                }
//            }
//        }
//        return res;

        /*
         * 方法3: 排序 + 双指针 (同方法2, 但是易于理解)
         * 时间复杂度 O(nlogn + n^2 = n^2), 空间复杂度 O(logn) (即快排的空间复杂度)
         */
        std::vector<std::vector<int>> ans;
        const int n = nums.size();
        if (n < 3) {
            return ans;
        }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            // 如果第一个数都大于0, 则和不可能为0
            if (nums[i] > 0) {
                break;
            }
            // 第一个数需要和上一次的数不相同
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1, k = n - 1; j < k;) {
                if (nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                } else {
                    ans.emplace_back(std::vector<int>{nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    // 第二个数不重复选取
                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    // 第三个数不重复选取
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    nums = {0, 0, 0, 0};
    auto res = Solution().threeSum(nums);
    print(res);
    return 0;
}