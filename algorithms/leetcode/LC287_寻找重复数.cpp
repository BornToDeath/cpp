//
// Created by lixiaoqing on 2022/7/18.
//

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        /**
         * 方法1：利用 std::bitset 。时间复杂度 O(n) ，空间复杂度 O(1)
         */
        std::bitset<100001> dp;
        for (auto num: nums) {
            if (dp[num]) {
                return num;
            }
            dp.set(num);
        }
        return -1;

        /**
         * 方法2：二分查找。时间复杂度 O(nlogn) ，空间复杂度 O(1)
         */
//        int left = 1, right = nums.size() - 1;
//        while (left < right) {
//            auto mid = (right - left) / 2 + left;
//            // 查找小于 mid 的元素个数
//            int count = std::count_if(nums.begin(), nums.end(), [mid](int num) { return num <= mid; });
//            if (count <= mid) {
//                left = mid + 1;
//            } else {
//                right = mid;
//            }
//        }
//        return left;

        /**
         * 方法3：快慢指针。时间复杂度 O(n) ，空间复杂度 O(1)
         */
//        int slow = 0, fast = 0;
//        do {
//            slow = nums[slow];
//            fast = nums[nums[fast]];
//        } while (slow != fast);
//        // 找环的入口节点，其为我们所求的数，因为入口节点有两个指针指向它
//        int cur = 0;
//        while (cur != slow) {
//            cur = nums[cur];
//            slow = nums[slow];
//        }
//        return cur;
    }
};

int main() {
//    std::vector<int> nums = {2, 2, 2, 2, 2};
    std::vector<int> nums = {3, 1, 3, 4, 2};
    std::cout << Solution().findDuplicate(nums) << std::endl;
    return 0;
}