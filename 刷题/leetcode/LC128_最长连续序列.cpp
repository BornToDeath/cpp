//
// Created by lixiaoqing on 2022/6/30.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int count = 0;
        std::unordered_set<int> set(nums.begin(), nums.end());
        for (int num: nums) {
            // 精髓在于此：前一个数如果在 set 中，是不参与统计的，参与统计的一定是每个连续序列的第一个元素
            if (set.find(num - 1) != set.end()) {
                continue;
            }
            int temp = num;
            while (set.find(temp) != set.end()) {
                ++temp;
            }
            count = std::max(count, temp - num);
        }
        return count;
    }
};

int main() {
//    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    std::cout << Solution().longestConsecutive(nums) << std::endl;
    return 0;
}