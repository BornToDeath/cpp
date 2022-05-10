//
// Created by lixiaoqing on 2022/5/10.
//

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberDisappeared(vector<int> &nums) {
        /**
         * 方法1：借助 std::map ，空间复杂度O(n)，时间复杂度O(logn)
         */
//        std::map<int, bool> _map;
//        for (auto num: nums) {
//            if (num > 0) {
//                _map[num] = true;
//            }
//        }
//        for (int i = 1; i <= nums.size(); ++i) {
//            if (_map.find(i) == _map.end()) {
//                return i;
//            }
//        }
//        return nums.size() + 1;

        /**
         * 方法2：空间复杂度O(1)，时间复杂度O(n)
         */
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != (i + 1)) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main() {
    std::vector<int> nums = {1, 1};
    std::cout << Solution().minNumberDisappeared(nums) << std::endl;
    return 0;
}