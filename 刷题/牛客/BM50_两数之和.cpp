//
// Created by lixiaoqing on 2022/5/9.
//

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::map<int, int> _map;
        for (int i = 0; i < numbers.size(); ++i) {
            if (_map.find(target - numbers[i]) == _map.end()) {
                _map[numbers[i]] = i + 1;
                continue;
            }
            return {_map[target - numbers[i]], i + 1};
        }
        return {};
    }
};

int main() {
    std::vector<int> nums = {20, 70, 110, 150};
    auto res = Solution().twoSum(nums, 90);
    for (const auto num: res) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}