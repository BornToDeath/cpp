//
// Created by lixiaoqing on 2022/5/25.
//

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

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
     * pick candy
     * @param arr int整型vector the array
     * @return int整型
     */
    int candy(vector<int> &arr) {
        /**
         * 1. 进行两次遍历，第一次从前往后，第二次从后往前
         */
        if (arr.empty()) {
            return 0;
        }
        std::vector<int> dp(arr.size(), 1);
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
//        print(dp);
        for (int i = arr.size() - 2; i >= 0; --i) {
            if (arr[i] > arr[i + 1] && dp[i] <= dp[i + 1]) {
                dp[i] = dp[i + 1] + 1;
            }
        }
//        print(dp);
        return std::accumulate(dp.begin(), dp.end(), 0);
    }
};

int main() {
    std::vector<int> arr = {50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28,
                            27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3,
                            2, 1};
    print(arr);
    std::cout << Solution().candy(arr) << std::endl;
    return 0;
}