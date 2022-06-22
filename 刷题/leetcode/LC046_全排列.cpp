//
// Created by lixiaoqing on 2022/6/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        std::vector<std::vector<int>> ans;
        permutation(nums, 0, ans);
        return ans;
    }

private:
    void permutation(vector<int> &nums, int pos, std::vector<std::vector<int>> &ans) {
        if (pos == nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); ++i) {
            std::swap(nums[i], nums[pos]);
            permutation(nums, pos + 1, ans);
            std::swap(nums[i], nums[pos]);
        }
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3};
    auto ans = Solution().permute(nums);
    for (auto &arr: ans) {
        for (auto num: arr) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}