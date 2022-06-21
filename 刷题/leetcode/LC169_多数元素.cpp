//
// Created by lixiaoqing on 2022/6/21.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        /**
         * 方法1：借助 std::sort()
         */
//        if (nums.empty()) {
//            return -1;
//        }
//        std::sort(nums.begin(), nums.end());
//        return nums[(nums.size() - 1) / 2];

        /**
         * 方法2（推荐）：时间复杂度O(n)，空间复杂度O(1)
         */
        int ele = 0, count = 0;
        for (auto num: nums) {
            if (count == 0) {
                ele = num;
            }
            num == ele ? ++count : --count;
        }
        return ele;

        /**
         * 方法3：利用 std::unordered_map
         */
//        std::unordered_map<int, int> umap;
//        for (auto num: nums) {
//            ++umap[num];
//            if (umap[num] > nums.size() / 2) {
//                return num;
//            }
//        }
//        return -1;
    }
};

int main() {
    std::vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    std::cout << Solution().majorityElement(arr) << std::endl;
    return 0;
}