//
// Created by lixiaoqing on 2023/2/7.
//

#include <vector>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        /**
         * 方法1：排序
         * 时间复杂度 O(nlogn) ，空间复杂度 O(logn)
         */
//        if (nums.empty()) {
//            return -1;
//        }
//        std::sort(nums.begin(), nums.end(), std::greater<int>());
//        for (int i = 1, j = 1; i < nums.size(); ++i) {
//            if (nums[i] != nums[i-1] && ++j == 3) {
//                return nums[i];
//            }
//        }
//        return nums[0];

        /**
         * 方法2：有序集合
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        if (nums.size() == 0) {
//            return -1;
//        }
//        std::set<int> s;
//        for (auto num: nums) {
//            s.insert(num);
//            if (s.size() > 3) {
//                s.erase(s.begin());
//            }
//        }
//        return s.size() == 3 ? *s.begin() : *s.rbegin();

        /**
         * 方法3：一次遍历
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        if (nums.empty()) {
            return -1;
        }
        long int a, b, c;
        a = b = c = LONG_MIN;
        for (auto num: nums) {
            if (num > a) {
                c = b;
                b = a;
                a = num;
            } else if (num < a && num > b) {
                c = b;
                b = num;
            } else if (num < b && num > c) {
                c = num;
            }
        }

        return c == LONG_MIN ? a : c;
    }
};

int main() {
    std::vector<int> nums;
    nums = {2, 2, 3, 1};
    std::cout << Solution().thirdMax(nums) << std::endl;
    nums = {1, 2};
    std::cout << Solution().thirdMax(nums) << std::endl;
    nums = {1, 2, 2, 5, 3, 5};
    std::cout << Solution().thirdMax(nums) << std::endl;
    return 0;
}