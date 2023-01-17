//
// Created by lixiaoqing on 2023/1/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        /**
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        std::vector<std::string> ans;
        for (int i = 0, left = 0; i < nums.size(); ++i) {
            if (i == nums.size() - 1 || nums[i + 1] != nums[i] + 1) {
                auto s = std::to_string(nums[left]);
                if (left < i) {
                    s.append("->").append(std::to_string(nums[i]));
                }
                ans.emplace_back(s);
                left = i + 1;
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {0, 1, 2, 4, 5, 7};
//    std::vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
    auto res = Solution().summaryRanges(nums);
    for (auto &s : res) {
        std::cout << s << std::endl;
    }
    return 0;
}