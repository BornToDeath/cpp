//
// Created by lixiaoqing on 2022/6/27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        /**
         * 方法1：递归
         */
//        std::vector<std::vector<int>> ans;
//        ans.push_back({});
//        for (int i = 1; i <= nums.size(); ++i) {
//            std::vector<int> set;
//            subsets(nums, i, 0, set, ans);
//        }
//        return ans;


        /**
         * 方法3：递归，比方法1容易理解。
         * 每个数字有选和不选两个状态。
         */
//        std::vector<std::vector<int>> ans;
//        std::vector<int> t;
//        dfs(nums, 0, t, ans);
//        return ans;

        /**
         * 方法2：位方法，每一个数表示一个位
         * 时间复杂度O(n * 2^n)，空间复杂度O(n)
         */
        std::vector<std::vector<int>> ans;
        std::vector<int> t;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    t.emplace_back(nums[i]);
                }
            }
            ans.emplace_back(t);
        }
        return ans;
    }

private:
    void dfs(std::vector<int> &nums, int pos, std::vector<int> &t, std::vector<std::vector<int>> &ans) {
        if (pos == nums.size()) {
            ans.emplace_back(t);
            return;
        }
        // 选
        t.emplace_back(nums[pos]);
        dfs(nums, pos + 1, t, ans);
        t.pop_back();
        // 不选
        dfs(nums, pos + 1, t, ans);
    }

    void subsets(std::vector<int> &nums, int size, int pos, std::vector<int> &set, std::vector<std::vector<int>> &ans) {
        if (size == set.size()) {
            ans.emplace_back(set);
            return;
        }
        for (int i = pos; i < nums.size(); ++i) {
            set.emplace_back(nums[i]);
//            printf(">>> pos=%d, i=%d\n", pos, i);
            subsets(nums, size, i + 1, set, ans);
            set.pop_back();
        }
    }
};

int main() {
    std::vector<int> nums = {1, 2, 4};
    auto ans = Solution().subsets(nums);
    for (auto &arr: ans) {
        for (auto num: arr) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}