//
// Created by lixiaoqing on 2022/9/23.
//

#include <iostream>
#include <vector>

using namespace std;

void print(const std::vector<int> &nums) {
    for (auto num : nums) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        /**
         * 方法1
         * 时间复杂度 O(n) ，空间复杂度 O(n)
         */
//        const int size = nums.size();
//        k %= size;
//        std::vector<int> temp(size);
//        for (int i = 0; i < size; ++i) {
//            temp[(i + k) % size] = nums[i];
//        }
//        std::copy(temp.begin(), temp.end(), nums.begin());

        /**
         * 方法2：逐轮后移。不AC，时间超限
         * 时间复杂度 O(kn) ，空间复杂度 O(1)
         */
//        const int size = nums.size();
//        k %= size;
//        for (int i = 0; i < k; ++i) {
//            auto ele = nums[size - 1];
//            for (int j = size - 1; j >= 1; --j) {
//                nums[j] = nums[j - 1];
//            }
//            nums[0] = ele;
//        }

        /**
         * 方法3：利用 std::reverse
         * 时间复杂度 O(n) ，空间复杂度 O(1)
         */
        if (nums.empty()) {
            return;
        }
        k %= nums.size();
        // 先翻转整个数组
        std::reverse(nums.begin(), nums.end());
        // 再翻转前 k 个元素
        std::reverse(nums.begin(), nums.begin() + k);
        // 再翻转剩下的元素
        std::reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    Solution().rotate(nums, 3);
    print(nums);
    return 0;
}