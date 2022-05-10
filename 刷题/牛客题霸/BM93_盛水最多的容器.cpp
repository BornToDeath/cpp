//
// Created by lixiaoqing on 2022/5/10.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param height int整型vector
     * @return int整型
     */
    int maxArea(vector<int> &height) {
        if (height.size() < 2) {
            return 0;
        }
        int max = -1;
        int left = 0, right = height.size() - 1;
        int flag = 0;
        while (left < right) {
            auto area = (right - left) * std::min(height[left], height[right]);
            if (area > max) {
                max = area;
            }
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max;
    }
};

int main() {
    std::vector<int> nums = {1, 7, 3, 2, 4, 5, 8, 2, 7};
    std::cout << Solution().maxArea(nums) << std::endl;
    return 0;
}