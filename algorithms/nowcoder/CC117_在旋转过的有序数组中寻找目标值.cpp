//
// Created by lixiaoqing on 2022/6/6.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @param target int整型
     * @return int整型
     */
    int search(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            auto mid = (end - start) / 2 + start;
            if (nums[mid] == target) {
                return mid;
            }
            // [start, mid] 有序
            if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
                // [mid, end] 有序
            else if (nums[mid] <= nums[end]) {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
//    std::vector<int> nums = {6, 8, 10, 0, 2, 4};
    std::vector<int> nums = {5, 1, 2, 3, 4};
    std::cout << Solution().search(nums, 5) << std::endl;
    return 0;
}