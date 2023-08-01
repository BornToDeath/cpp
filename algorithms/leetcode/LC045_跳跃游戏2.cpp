//
// Created by lixiaoqing on 2023/7/27.
//

#include <iostream>
#include <vector>

using std::vector;

template<typename T>
void print(const std::vector<T> &arr) {
    for (const auto &o : arr) {
        std::cout << o << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    int jump(vector<int> &nums) {
        /*
         * 方法: 贪心
         * 时间复杂度 O(n), 空间复杂度 O(1)
         */
        int step = 0;  // 跳跃次数
        int end = 0;   // 上次跳跃的可达范围右边界
        int maxPos = 0;  // 目前能跳到的最远位置
        for (int i = 0; i < nums.size() - 1; ++i) {
            maxPos = std::max(maxPos, i + nums[i]);
            if (i == end) {  // 到达上次跳跃能到达的右边界了, 若要超过该位置, 必须要进行一次跳跃
                end = maxPos;  // 更新右边界
                ++step;  // 进入下一次跳跃
            }
        }
        return step;
    }
};

int main() {
    std::vector<int> nums = {2, 3, 1, 1, 4};
    nums = {2, 3, 0, 1, 4};
    nums = {2, 0, 0, 1, 1};  // 无效用例, 题目保证可以到达末尾
    nums = {1, 2, 3};
    nums = {1};
    std::cout << Solution().jump(nums) << std::endl;
    return 0;
}