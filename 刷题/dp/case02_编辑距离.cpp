//
// Created by lixiaoqing on 2023/1/6.
//

#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<int> &arr) {
    for (auto e: arr) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

template<typename T>
void print(const std::vector<T> &arr) {
    for (auto &e: arr) {
        print(e);
    }
}

class Solution {
public:
    int editDistance(std::string str1, std::string str2) {
        int m = str1.size(), n = str2.size();
        if (m == 0 && n == 0) {
            return 0;
        } else if (m == 0) {
            return n;
        } else if (n == 0) {
            return m;
        }

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min(dp[i - 1][j - 1] + 1, std::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
            }
        }
//        print(dp);

        return dp[m][n];
    }
};

int main() {
    std::string str1 = "horse";
    std::string str2 = "ros";
    std::cout << Solution().editDistance(str1, str2) << std::endl;
    return 0;
}