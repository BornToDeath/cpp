//
// Created by lixiaoqing on 2022/6/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                int j = nums.size() - 1;
                while (j > i && nums[j] <= nums[i]) {
                    --j;
                }
                swap(nums[i], nums[j]);
                std::reverse(nums.begin() + i + 1, nums.end());
                break;
            }
            if (i == 0) {
                std::reverse(nums.begin(), nums.end());
            }
        }
    }
};

int main() {
    std::vector<int> arr = {3, 2, 1};
    Solution().nextPermutation(arr);
    for (auto num: arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;

//    std::vector<std::vector<int>> arrs = {
//            {23, 31, 7},
//            {23, 7,  31},
//            {7,  31, 23},
//            {7,  23, 31},
//            {31, 7,  23},
//            {31, 23, 7}
//    };
//    std::sort(arrs.begin(), arrs.end());
//    for (auto &arr: arrs) {
//        for (auto num: arr) {
//            std::cout << num << ", ";
//        }
//        std::cout << std::endl;
//    }
    return 0;
}