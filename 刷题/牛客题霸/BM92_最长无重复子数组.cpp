//
// Created by lixiaoqing on 2022/5/25.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void print(std::vector<int> &arr) {
    for (auto num: arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int> &arr) {
        /**
         * 方法1：map + 数组
         */
//        std::unordered_map<int, int> _map;
//        std::vector<int> dp(arr.size() + 1, 0);
//        for (int i = 0; i < arr.size(); ++i) {
//            if (_map.find(arr[i]) == _map.end()) {
//                dp[i + 1] = dp[i] + 1;
//            } else {
//                dp[i + 1] = std::min(i - _map[arr[i]], dp[i] + 1);
//            }
//            _map[arr[i]] = i;
//        }
//        print(dp);
//        return *std::max_element(dp.begin(), dp.end());

        /**
         * 方法2：map + 滑动窗口
         */
//        int max = 0;
//        // map 中 value 是 key 出现的下标
//        std::unordered_map<int, int> _map;
//        for (int i = 0, j = 0; j < arr.size(); ++j) {
//            if (_map.find(arr[j]) != _map.end()) {
//                i = std::max(i, _map[arr[j]] + 1);
//            }
//            _map[arr[j]] = j;
//            max = std::max(max, j - i + 1);
//        }
//        return max;

        /**
         * 方法3（推荐）：map + 滑动窗口（窗口内的元素都是不重复的）
         */
        int max = 0;
        // map 中 value 记录 key 出现的次数
        std::unordered_map<int, int> _map;
        for (int i = 0, j = 0; j < arr.size(); ++j) {
            _map[arr[j]]++;
            while (_map[arr[j]] > 1) {
                _map[arr[i++]]--;
            }
            max = std::max(max, j - i + 1);
        }
        return max;

        /**
         * 方法4：数组。数组中只保存无重复元素
         */
//        int max = 0;
//        std::vector<int> dp;
//        for (auto num: arr) {
//            if (std::find(dp.begin(), dp.end(), num) != dp.end()) {
//                while (!dp.empty() && dp.front() != num) {
//                    dp.erase(dp.begin());
//                }
//                if (!dp.empty()) {
//                    dp.erase(dp.begin());
//                }
//            }
//            dp.push_back(num);
//            max = std::max(max, (int) dp.size());
//        }
//        return max;
    }
};

int main() {
    std::vector<int> arr = {3, 3, 2, 1, 3, 3, 3, 1};
    std::cout << Solution().maxLength(arr) << std::endl;
    return 0;
}