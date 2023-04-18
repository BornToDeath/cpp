//
// Created by lixiaoqing on 2023/4/18.
//

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        if (numbers.empty()) {
            return {};
        }
        for (int i = 0, j = numbers.size() - 1; i < j;) {
            if (numbers[i] + numbers[j] == target) {
                return {i, j};
            } else if (numbers[i] + numbers[j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        return {};
    }
};