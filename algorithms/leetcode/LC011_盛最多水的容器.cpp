//
// Created by lixiaoqing on 2022/6/17.
//

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            auto area = (j - i) * std::min(height[i], height[j]);
            max = std::max(max, area);
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return max;
    }
};