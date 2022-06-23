//
// Created by lixiaoqing on 2022/6/23.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> ans;
        for (auto &inter: intervals) {
            if (ans.empty() || inter[0] > ans.back()[1]) {
                ans.emplace_back(inter);
            } else {
                ans.back()[1] = std::max(ans.back()[1], inter[1]);
            }
        }
        return ans;
    }
};

int main() {
    std::vector<std::vector<int>> intervals;
    Solution().merge(intervals);
    return 0;
}