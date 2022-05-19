//
// Created by lixiaoqing on 2022/5/19.
//

#include <vector>
#include <iostream>

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
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int> &arr, int aim) {
        // 完全背包问题
        std::vector<int> dp(aim + 1, aim + 1);
        dp[0] = 0;
        for (int i = 1; i <= aim; ++i) {
            for (int j = 0; j < arr.size(); ++j) {
                if (arr[j] <= i) {
                    dp[i] = std::min(dp[i], dp[i - arr[j]] + 1);
                }
            }
        }
//        print(dp);
        return (dp[aim] == aim + 1) ? -1 : dp[aim];
    }

private:
    int minMoney(vector<int> &arr, int index, int aim) {
        if (aim == 0) {
            return 0;
        } else if (aim < 0 || index >= arr.size()) {
            return -1;
        }
        if (aim >= arr[index]) {
            auto count = minMoney(arr, index, aim - arr[index]);
            if (count != -1) {
                printf("index=%d, money=%d, count=%d, aim=%d\n", index, arr[index], count + 1, aim - arr[index]);
                return count + 1;
            }
        }
        return minMoney(arr, index + 1, aim);
    }
};

int main() {
    std::vector<int> arr = {2, 5, 3};
    int aim = 17; // 596; // 961
    std::cout << Solution().minMoney(arr, aim) << std::endl;
    return 0;
}