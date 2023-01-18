//
// Created by lixiaoqing on 2022/10/12.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void print(std::vector<std::vector<T>> &matrix) {
    for (auto &arr: matrix) {
        for (auto e: arr) {
            std::cout << e << ", ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str1 string字符串
     * @param str2 string字符串
     * @return int整型
     */
    int editDistance(string str1, string str2) {
        /**
         * 动态规划
         * 参考：https://www.cnblogs.com/yulinfeng/p/7096882.html
         * 时间复杂度 O(mn) ，空间复杂度 O(mn)
         */
        const int size1 = str1.length(), size2 = str2.length();
        std::vector<std::vector<int>> dp(size1 + 1, std::vector<int>(size2 + 1, 0));
        for (int i = 0; i <= size1; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= size2; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= size1; ++i) {
            for (int j = 1; j <= size2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
//                    dp[i][j] = dp[i][j - 1] + 1;      // 添加
//                    dp[i][j] = dp[i - 1][j] + 1;      // 删除
//                    dp[i][j] = dp[i - 1][j - 1] + 1;  // 修改
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
//        print(dp);
        return dp[size1][size2];
    }
};

int main() {
    std::string str1 = "lrbb", str2 = "mqbhcda";
    std::cout << Solution().editDistance(str1, str2) << std::endl;
    return 0;
}