//
// Created by lixiaoqing on 2023/4/7.
//

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using std::vector;
using std::string;

class Solution {
public:
    string minNumber(vector<int> &nums) {
        /*
         * 方法: 利用 std::sort , 关键是排序规则
         * 时间复杂度 O(nlogn) , 空间复杂度 O(n)
         */
        std::vector<std::string> v(nums.size());
        std::transform(nums.begin(), nums.end(), v.begin(), [](int num) { return std::to_string(num); });
        std::sort(v.begin(), v.end(), [](const std::string &s1, const std::string &s2) {
            // 这是关键
            return s1 + s2 < s2 + s1;
        });
        return std::accumulate(v.begin(), v.end(), std::string(""));
    }
};


int main() {
    std::vector<int> nums;
    nums = {3, 333, 3330, 3335};
    nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    nums = {824, 938, 1399, 5607, 6973, 5703, 9609, 4398, 8247};
//    nums = {824, 8247};
    std::cout << Solution().minNumber(nums) << std::endl;
    std::cout << "1399439856075703697382478249389609" << std::endl;
    // "1399439856075703697382478249389609"
    return 0;
}