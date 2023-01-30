//
// Created by lixiaoqing on 2023/1/30.
//

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

/**
 * 方法1：累加求和
 */
//class NumArray {
//public:
//    NumArray(vector<int> &nums) {
//        nums = nums;
//    }
//
//    int sumRange(int left, int right) {
//        return std::accumulate(nums.begin() + left, nums.begin() + right + 1, 0);
//    }
//
//private:
//    std::vector<int> nums;
//};

/**
 * 方法2：前缀和
 */
class NumArray {
public:
    NumArray(vector<int> &nums) {
        sums.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }

private:
    std::vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
    std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray arr(nums);
    std::cout << arr.sumRange(0, 2) << std::endl;
    std::cout << arr.sumRange(2, 5) << std::endl;
    std::cout << arr.sumRange(0, 5) << std::endl;
    return 0;
}