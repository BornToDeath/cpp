//
// Created by lixiaoqing on 2022/6/13.
//

#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_set>

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
     * @param num int整型vector
     * @return int整型
     */
    int longestConsecutive(vector<int> &num) {
        /**
         * 方法1：用 std::vector, 但是这种方法空间复杂度较高
         */
//        auto min = *std::min_element(num.begin(), num.end());
//        auto max = *std::max_element(num.begin(), num.end());
//        std::vector<int> dp(max - min + 1, 0);
//        for (auto ele: num) {
//            dp[ele - min] = 1;
//        }
////        print(dp);
//        int maxLen = 0, count = 0;
//        for (int i : dp) {
//            if (i == 1) {
//                ++count;
//                maxLen = std::max(maxLen, count);
//            } else {
//                count = 0;
//            }
//        }
//        return maxLen;

        /**
         * 方法2：借助哈希表
         */
        int maxLen = 0, len = 1;
        std::unordered_set<int> _uset(num.begin(), num.end());
        for (auto ele: num) {
            if (_uset.find(ele) == _uset.end()) {
                continue;
            }
            _uset.erase(ele);
            int left = ele, right = ele;
            while (_uset.find(--left) != _uset.end()) {
                _uset.erase(left);
            }
            while (_uset.find(++right) != _uset.end()) {
                _uset.erase(right);
            }
            maxLen = std::max(maxLen, right - left - 1);
        }
        return maxLen;
    }
};

int main() {
//    std::vector<int> arr = {1, 2, 3, 10, 11, 12, 13, 5};
    std::vector<int> arr = {0, 0, -1};
    std::cout << Solution().longestConsecutive(arr) << std::endl;
}