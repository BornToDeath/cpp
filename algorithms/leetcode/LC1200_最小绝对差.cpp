//
// Created by lixiaoqing on 2022/7/4.
//

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        std::vector<std::vector<int>> ans;
        std::sort(arr.begin(), arr.end());
        int diff = std::numeric_limits<int>::max();
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] > diff) {
                continue;
            } else if (arr[i + 1] - arr[i] < diff) {
                diff = arr[i + 1] - arr[i];
                ans.clear();
            }
            ans.push_back({arr[i], arr[i + 1]});
        }
        return ans;
    }
};