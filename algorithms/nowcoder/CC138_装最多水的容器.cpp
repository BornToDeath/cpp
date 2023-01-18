//
// Created by lixiaoqing on 2022/6/6.
//

#include <vector>

using namespace std;

class Solution {
public:
    /**
     *
     * @param height int整型vector
     * @return int整型
     */
    int maxArea(vector<int> &height) {
        int max = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            max = std::max((right - left) * std::min(height[right], height[left]), max);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max;
    }
};