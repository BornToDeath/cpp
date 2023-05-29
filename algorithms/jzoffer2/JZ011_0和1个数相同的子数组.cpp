//
// Created by lixiaoqing on 2023/5/29.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        /*
         * 方法: 前缀和 + 哈希表. n 遇到 1 就 +1 , 遇到 0 就 -1 , 并记录 map[n] 的下标
         * 时间复杂度 O(n) , 空间复杂度 O(n)
         */
        int ans = 0, n = 0;
        std::unordered_map<int, int> _map;
        _map.insert({0, -1});
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] ? ++n : --n;
            if (_map.count(n) == 0) {
                _map[n] = i;
            } else {
                ans = std::max(ans, i - _map[n]);
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {0, 1, 1, 0};
    nums = {0, 1, 1, 0, 1, 1, 1, 0};
    std::cout << Solution().findMaxLength(nums) << std::endl;
    return 0;
}