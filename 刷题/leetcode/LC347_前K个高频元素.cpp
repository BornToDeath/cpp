//
// Created by lixiaoqing on 2022/7/25.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        /**
         * 方法1：先计数，然后取出现次数较大的前 k 个元素
         * 时间复杂度 O(kn) ，空间复杂度 O(n)
         */
//        std::unordered_map<int, int> dp;
//        for (auto num: nums) {
//            ++dp[num];
//        }
//        std::vector<int> times;
//        for (auto &ele: dp) {
//            times.emplace_back(ele.second);
//        }
//        std::sort(times.begin(), times.end(), std::greater<int>());
//        std::vector<int> ans;
//        for (int i = 0; i < k; ++i) {
//            for (auto &ele: dp) {
//                if (ele.second == times[i]) {
//                    ans.emplace_back(ele.first);
//                    dp.erase(ele.first);
//                    break;
//                }
//            }
//        }
//        return ans;

        /**
         * 方法2：利用堆。C++ std::priority_queue 就是堆
         * 时间复杂度 O(nkogk) ，空间复杂度 O(n)
         */
        // <值，次数>
        std::unordered_map<int, int> map;
        for (auto num: nums) {
            ++map[num];
        }
        // <次数，值>
        std::priority_queue<std::pair<int, int>> queue;
        for (auto &ele: map) {
            queue.emplace(ele.second, ele.first);
        }
        std::vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(queue.top().second);
            queue.pop();
        }
        return ans;
    }

private:

};

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    auto ans = Solution().topKFrequent(nums, 2);
    for (auto ele: ans) {
        std::cout << ele << ", ";
    }
    std::cout << std::endl;
    return 0;
}