//
// Created by lixiaoqing on 2023/3/6.
//

#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::map;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &score) {
        /**
         * 方法1：借助 map
         * 时间复杂度 O(nlogn) ，空间复杂度 O(n)
         */
//        std::map<int, int, std::greater<int>> _map;
//        for (auto n: score) {
//            _map.insert({n, 0});
//        }
//        int index = 1;
//        for (auto e: _map) {
//            _map[e.first] = index++;
//        }
//        std::vector<std::string> ans(score.size());
//        for (int i = 0; i < ans.size(); ++i) {
//            auto rank = _map[score[i]];
//            if (rank == 1) {
//                ans[i] = "Gold Medal";
//            } else if (rank == 2) {
//                ans[i] = "Silver Medal";
//            } else if (rank == 3) {
//                ans[i] = "Bronze Medal";
//            } else {
//                ans[i] = std::to_string(rank);
//            }
//        }
//        return ans;

        /**
         * 方法2：对 score 进行排序
         * 时间复杂度 O(nlogn) ，空间复杂度 O(n)
         */
        const std::vector<std::string> MEDALS = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        const int size = score.size();
        std::vector<std::pair<int, int >> v(size);
        for (int i = 0; i < size; ++i) {
            v[i] = {score[i], i};
        }
        // 按照分数从大到小排队
        std::sort(v.begin(), v.end(), std::greater<std::pair<int, int>>());
        std::vector<std::string> ans(size);
        for (int i = 0; i < size; ++i) {
            ans[v[i].second] = i < 3 ? MEDALS[i] : std::to_string(i + 1);
        }
        return ans;
    }
};

int main() {
    std::vector<int> score = {10, 3, 8, 9, 4};
    auto ans = Solution().findRelativeRanks(score);
    for (auto &e: ans) {
        std::cout << e << std::endl;
    }
    return 0;
}