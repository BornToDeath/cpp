//
// Created by lixiaoqing on 2023/6/29.
//

#include <vector>
#include <iostream>

using std::vector;

void print(const std::vector<int> &arr) {
    for (auto n: arr) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        /*
         * 方法1: 双向遍历, 维护两个数组
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
//        const int size = nums.size();
//        std::vector<int> leftMin(size, 0), rightMax(size, 0);
//        for (int i = 0; i < size; ++i) {
//            leftMin[i] = i == 0 ? nums[i] : std::min(leftMin[i - 1], nums[i - 1]);
//        }
//        for (int i = size - 1; i >= 0; --i) {
//            rightMax[i] = i == size - 1 ? nums[i] : std::max(rightMax[i + 1], nums[i + 1]);
//        }
////        print(leftMin);
////        print(nums);
////        print(rightMax);
//        for (int i = 1; i < size - 1; ++i) {
//            if (leftMin[i] < nums[i] && nums[i] < rightMax[i]) {
//                return true;
//            }
//        }
//        return false;

        /*
         * 方法2: 贪心
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         */
        int first = nums.front(), second = std::numeric_limits<int>::max();
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > second) {
                return true;
            } else if (nums[i] > first) {
                second = nums[i];
            } else {
                first = nums[i];
            }
        }
        return false;
    }
};

int main() {
    std::vector<int> nums = {2, 1, 5, 0, 4, 6};
    nums = {20, 100, 10, 12, 5, 13};
    std::cout << Solution().increasingTriplet(nums) << std::endl;
    return 0;
}