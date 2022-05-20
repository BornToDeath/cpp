//
// Created by lixiaoqing on 2022/5/20.
//

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> &arr) {
    for (auto num:arr) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定数组的最长严格上升子序列的长度。
     * @param arr int整型vector 给定的数组
     * @return int整型
     */
    int LIS(vector<int> &arr) {
        if (arr.empty()) {
            return 0;
        }
        std::vector<int> dp(arr.size(), 1);
        for (int i = 1; i < arr.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] > arr[j]) {
                    dp[i] = std::max(dp[i], 1 + dp[j]);
                }
            }
        }
//        print(dp);
        return *std::max_element(dp.begin(), dp.end());
    }
};

int main() {
    std::vector<int> arr = {1, 6, 4, 7, 5, 3, 2};
    std::cout << Solution().LIS(arr) << std::endl;
    return 0;
}