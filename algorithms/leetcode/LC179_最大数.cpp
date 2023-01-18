//
// Created by lixiaoqing on 2022/9/19.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template<typename T>
void print(std::vector<T> &arr) {
    for (auto &e: arr) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        /**
         * 时间复杂度 O(nlogn) ，空间复杂度 O(n)
         */
        if (nums.empty()) {
            return "";
        }
        std::vector<std::string> strs(nums.size());
        std::transform(nums.begin(), nums.end(), strs.begin(), [](int num) { return std::to_string(num); });
        std::sort(strs.begin(), strs.end(), [](std::string &s1, std::string s2) {
            return s1 + s2 > s2 + s1;
        });
        auto ans = std::accumulate(strs.begin(), strs.end(), std::string(""));
        return ans[0] == '0' ? "0" : ans;
    }
};


int main() {
    std::vector<int> nums = {3, 30, 34, 5, 9};
    std::cout << Solution().largestNumber(nums) << std::endl;
    return 0;
}