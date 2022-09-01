//
// Created by lixiaoqing on 2022/9/1.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        /**
         * 方法：借助 std::unordered_set
         */
        std::unordered_set<int> set;
        for (auto n: nums) {
            if (set.count(n)) {
                return true;
            }
            set.insert(n);
        }
        return false;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::cout << Solution().containsDuplicate(nums) << std::endl;
}