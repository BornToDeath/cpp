//
// Created by lixiaoqing on 2022/3/24.
//

#include <iostream>
#include <vector>

using namespace std;

void printArray(const std::vector<int> &array) {
    std::copy(array.begin(), array.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
}

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        /**
         * 方法1：空间复杂度 O(n)
         */
//        if (array.empty()) {
//            return -1;
//        }
//        std::vector<int> dp;
//        int sum = array[0];
//        dp.emplace_back(sum);
//        for (int i = 1; i < array.size(); ++i) {
//            if (sum >= 0 && sum + array[i] >= 0) {
//                sum += array[i];
//                dp.emplace_back(sum);
//            } else {
//                sum = array[i];
//                dp.emplace_back(sum);
//            }
//        }
//        auto it = std::max_element(dp.begin(), dp.end());
//        return *it;

        /**
        * 方法2：空间复杂度 O(n)
        * dp[i]表示以元素array[i]结尾的连续子数组最大和，则：
        *   dp[i] :
        *     = dp[i-1] + array[i], dp[i-1] >= 0
        *     = array[i],           dp[i-1] < 0
        */
//        if (array.empty()) {
//            return {};
//        }
//
//        vector<int> dp(array.size());
//        for (int i = 0; i < array.size(); ++i) {
//            if (i == 0) {
//                dp[i] = array[i];
//                continue;
//            }
//            if (dp[i - 1] >= 0) {
//                dp[i] = dp[i - 1] + array[i];
//            } else {
//                dp[i] = array[i];
//            }
//        }
//        auto it = std::max_element(dp.begin(), dp.end());
//        return *it;

        /**
         * 方法3：空间复杂度 O(1)
         */
        if (array.empty()) {
            return -1;
        }
        int sum = array[0];
        int max = sum;
        for (int i = 1; i < array.size(); ++i) {
            if (sum >= 0 && sum + array[i] >= 0) {
                sum += array[i];
            } else {
                sum = array[i];
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};

int main() {
    std::vector<int> array = {1, -2, 3, 10, -4, 7, 2, -5};
    std::cout << Solution().FindGreatestSumOfSubArray(array) << std::endl;
}