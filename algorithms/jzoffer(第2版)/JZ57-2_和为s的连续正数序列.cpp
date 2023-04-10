//
// Created by lixiaoqing on 2023/3/27.
//

#include <vector>
#include <numeric>
#include <iostream>

using std::vector;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        /*
         * 方法1：暴力搜索
         * 时间复杂度 O(target * pow(target, 0.5)) , 空间复杂度 O(1)
         */
//        std::vector<std::vector<int>> ans;
//        for (int i = 1; i <= ((target - 1) >> 1); ++i) {
//            int j = i, sum = 0;
//            while (sum < target) {
//                sum += j;
//                ++j;
//            }
//            if (sum == target) {
//                std::vector<int> v(j - i);
//                for (int k = i; k < j; ++k) {
//                    v[k - i] = k;
//                }
//                ans.emplace_back(v);
//            }
//        }
//        return ans;

        /*
         * 方法2：双指针
         * 时间复杂度 O(target) , 空间复杂度 O(1)
         */
        auto intervalSum = [](int l, int r) -> int {
            return (r - l + 1) * (l + r) / 2;
        };
        std::vector<std::vector<int>> ans;
        for (int l = 1, r = 2; l < r;) {
            auto sum = intervalSum(l, r);
            if (sum == target) {
                ans.emplace_back(std::vector<int>(r - l + 1));
                for (int k = l; k <= r; ++k) {
                    ans.back().at(k - l) = k;
                }
                ++l;
                ++r;
            } else if (sum < target) {
                ++r;
            } else {
                ++l;
            }
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().findContinuousSequence(15);
    for (auto &v: ans) {
        for (auto n: v) {
            std::cout << n << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}