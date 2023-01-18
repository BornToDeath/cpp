//
// Created by lixiaoqing on 2022/6/28.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void print(std::vector<int> &nums) {
    for (auto num: nums) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        /**
         * 方法1：借助 std::unordered_set
         */
//        std::unordered_set<int> set(nums.begin(), nums.end());
//        std::vector<int> ans;
//        for (int i = 1; i <= nums.size(); ++i) {
//            if (set.find(i) == set.end()) {
//                ans.emplace_back(i);
//            }
//        }
//        return ans;

        /**
         * 方法2：交换数组中的元素，使之与索引相对应
         */
//        for (int i = 0; i < nums.size();) {
//            if (nums[i] != nums[nums[i] - 1]) {
//                std::swap(nums[i], nums[nums[i] - 1]);
//            } else {
//                ++i;
//            }
//        }
//        std::vector<int> ans;
//        for (int i = 1; i <= nums.size(); ++i) {
//            if (i != nums[i - 1]) {
//                ans.emplace_back(i);
//            }
//        }
//        return ans;

        /**
         * 方法3：
         * 将数组元素对应为索引的位置加n
         * 遍历加n后的数组，若数组元素值小于等于n，则说明数组下标值不存在，即为消失的数字
         */
//        int n = nums.size();
//        for (auto num: nums) {
//            nums[(num - 1) % n] += n;
//        }
//        std::vector<int> ans;
//        for (int i = 1; i <= n; ++i) {
//            if (nums[i - 1] <= n) {
//                ans.emplace_back(i);
//            }
//        }
//        return ans;

        /**
         * 方法4：将数组元素对应为索引的位置的元素置为负数，遍历数组后，仍为正数的元素即消失的数字
         */
        for (auto num: nums) {
            nums[std::abs(num) - 1] = -std::abs(nums[std::abs(num) - 1]);
        }
        std::vector<int> ans;
        for (int i = 1; i <= nums.size(); ++i) {
            if (nums[i - 1] > 0) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    auto ans = Solution().findDisappearedNumbers(nums);
    print(ans);
    return 0;
}

