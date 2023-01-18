//
// Created by lixiaoqing on 2022/6/13.
//

#include <iostream>
#include <vector>

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
     * @param rowIndex int整型
     * @return int整型vector
     */
    vector<int> getRow(int rowIndex) {
        std::vector<int> dp(rowIndex + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp;
    }
};

int main() {
    auto res = Solution().getRow(4);
    print(res);
    return 0;
}