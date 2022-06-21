//
// Created by lixiaoqing on 2022/6/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        /**
         * 方法1：递归
         */
        std::vector<std::vector<int>> res;
        std::vector<int> ele;
        combination(0, candidates, target, ele, res);
        return res;

        /**
         * 方法2：还是递归
         * 这是 leetcode 的官方解法，可以AC，但是有一个问题：当 candidates 中含有重复数字时，答案中存在重复元素，如下示例。
         * 示例：candidates = {2, 2}, target = 8 时，此解法的输出为：
         *   {{2, 2, 2, 2},
         *    {2, 2, 2, 2},
         *    {2, 2, 2, 2},
         *    {2, 2, 2, 2},
         *    {2, 2, 2, 2}}
         *  可是这个解法真的符合题意吗？
         *  方法1的解法是不存在这个问题的。
         */
//        std::vector<std::vector<int>> ans;
//        std::vector<int> combine;
//        dfs(candidates, target, ans, combine, 0);
//        return ans;
    }

private:
    void dfs(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 跳过当前数
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    void combination(int pos, vector<int> &candidates, int target, std::vector<int> &ele,
                     std::vector<std::vector<int>> &res) {
        if (target <= 0) {
            if (target == 0) {
                res.emplace_back(ele);
            }
            return;
        }
        for (int i = pos; i < candidates.size(); ++i) {
            if (i > 0 && candidates[i] == candidates[i - 1]) {
                continue;
            }
            ele.emplace_back(candidates[i]);
            combination(i, candidates, target - candidates[i], ele, res);
            ele.pop_back();
        }
    }
};

int main() {
    std::vector<int> candidates = {2, 2};
    int target = 8;
    auto res = Solution().combinationSum(candidates, target);
    for (auto &arr: res) {
        for (auto num: arr) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}