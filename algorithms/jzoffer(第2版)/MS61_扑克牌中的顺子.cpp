//
// Created by lixiaoqing on 2023/4/10.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;

class Solution {
public:
    bool isStraight(vector<int> &nums) {
        /*
         * 方法: 利用哈希表
         * 时间复杂度 O(n) , 空间复杂度 O(n) , 其中 n = 5
         */
//        int zeroCount = 0, minNum = -1;
//        std::unordered_set<int> s;
//        for (auto num: nums) {
//            if (num == 0) {
//                ++zeroCount;
//                continue;
//            }
//            s.insert(num);
//            if (minNum == -1 || num < minNum) {
//                minNum = num;
//            }
//        }
//        for (int i = minNum; i < minNum + 5; ++i) {
//            if (s.count(i) == 1) {
//                continue;
//            }
//            --zeroCount;
//            if (zeroCount < 0) {
//                return false;
//            }
//        }
//        return true;

        /*
         * 方法2: 在方法1的基础上上进行优化: max - min < 5
         * 时间复杂度 O(n) , 空间复杂度 O(n) , 其中 n = 5
         */
        int max = -1, min = 14;
        std::unordered_set<int> s;
        for (auto num: nums) {
            if (num == 0) {
                continue;
            }
            if (s.count(num)) {
                return false;
            }
            s.insert(num);
            max = std::max(max, num);
            min = std::min(min, num);
        }
        return max - min < 5;

        /*
         * 方法3: 先排序, 再判断: max - min < 5
         * 时间复杂度 O(nlogn) , 空间复杂度 O(1) , 其中 n = 5
         */
//        std::sort(nums.begin(), nums.end());
//        int zeroCount = 0;
//        for (int i = 0; i < 4; ++i) {
//            if (nums[i] == 0) {
//                ++zeroCount;
//                continue;
//            }
//            if (nums[i] == nums[i + 1]) {
//                return false;
//            }
//        }
//        return nums[4] - nums[zeroCount] < 5;
    }
};

int main() {
    std::vector<int> nums = {0, 0, 1, 5, 6};
    nums = {0, 0, 8, 5, 4};
    std::cout << Solution().isStraight(nums) << std::endl;
    return 0;
}