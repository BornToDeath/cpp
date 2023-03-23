//
// Created by lixiaoqing on 2023/3/23.
//

#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        /*
         * 方法1：先排序再比较
         * 时间复杂度 O(nlogn) , 空间复杂度 O(1)
         */
//        std::sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); i += 3) {
//            if (i == nums.size() - 1 || nums[i] != nums[i + 1]) {
//                return nums[i];
//            }
//        }
//        return -1;

        /*
         * 方法2：计算各个位的和
         * 时间复杂度 O(nC) , 其中 C 为 32 , 空间复杂度 O(1)
         */
//        int ans = 0;
//        for (int i = 0; i < 32; ++i) {
//            int sum = 0;
//            for (auto n: nums) {
//                sum += ((n >> i) & 1);
//            }
//            ans |= ((sum % 3) << i);
//        }
//        return ans;

        /*
         * 方法3: 有限状态自动机
         * 时间复杂度 O(n) , 空间复杂度 O(1)
         * https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/mian-shi-ti-56-ii-shu-zu-zhong-shu-zi-chu-xian-d-4/
         */
        int one = 0, two = 0;
        for (auto n : nums) {
            one = one ^ n & ~two;
            two = two ^ n & ~one;
        }
        return one;
    }
};

int main() {
    std::vector<int> nums = {3, 3, 3, 4};
    std::cout << Solution().singleNumber(nums) << std::endl;
    return 0;
}
