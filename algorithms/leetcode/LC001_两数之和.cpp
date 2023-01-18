//
// Created by lixiaoqing on 2022/6/14.
//

#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        /**
         * 方法1：时间复杂度O(n^2)
         */
//        for (int i = 0; i < nums.size(); ++i) {
//            for (int j = i + 1; j < nums.size(); ++j) {
//                if (nums[i] + nums[j] == target) {
//                    return {i, j};
//                }
//            }
//        }
//        return {};

        /**
         * 方法2：借助std::map，时间复杂度O((logn)^2)
         */
//        std::map<int, int> map;
//        for (int i = 0; i < nums.size(); ++i) {
//            if (map.find(target - nums[i]) != map.end()) {
//                return {map[target - nums[i]], i};
//            }
//            map[nums[i]] = i;
//        }
//        return {};

        /**
         * 方法3：借助 std::unordered_map，时间复杂度为O(n)
         */
        std::unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            if (umap.find(target - nums[i]) != umap.end()) {
                return {umap[target - nums[i]], i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};
