//
// Created by lixiaoqing on 2022/5/20.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(std::vector<std::vector<int>> &matrix) {
    for (auto &arr: matrix) {
        for (auto num: arr) {
            std::cout << num << ", ";
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
     * @param A string字符串
     * @return int整型
     */
    int getLongestPalindrome(string A) {
        /**
         * 方法1：双指针，两边向中间移动。
         * 时间复杂度O(n^2), 空间复杂度O(1)
         */
//        if (A.empty()) {
//            return 0;
//        }
//        int count = 1;
//        for (int i = 0; i < A.length(); ++i) {
//            if (count >= A.length() - i) {
//                continue;
//            }
//            for (int j = A.length() - 1; j > i; --j) {
//                int left = i;
//                int right = j;
//                bool flag = true;
//                while (left < right) {
//                    if (A[left] != A[right]) {
//                        flag = false;
//                        break;
//                    }
//                    ++left;
//                    --right;
//                }
//                if (flag) {
//                    count = std::max(count, j - i + 1);
//                    break;
//                }
//            }
//        }
//        return count;

        /**
         * 方法2：动态规划。dp[i][j] = dp[i+1][j-1] + 2
         * 时间复杂度O(n^2)，空间复杂度O(n^2)
         */
        if (A.empty()) {
            return 0;
        }
        int max = 1;
        int len = A.length();
        // dp[i][j]表示第i个字符串到第j个字符串所表示的回文串的长度。只用 dp 的右上部分
        std::vector<std::vector<int>> dp(len, std::vector<int>(len, 0));
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i; j < len; ++j) {
                if (i == j) {
                    // 对角线元素
                    dp[i][j] = 1;
                } else {
                    if (A[i] == A[j]) {
                        if (i + 1 == j) {
                            // 次长对角线元素
                            dp[i][j] = 2;
                        } else if (dp[i + 1][j - 1] != 0) {
                            // 其他元素: dp[i][j] = dp[i+1][j-1]
                            dp[i][j] = dp[i + 1][j - 1] + 2;
                        }
                    }
                }
                max = std::max(dp[i][j], max);
            }
        }
//        print(dp);
        return max;
    }
};

int main() {
//    std::string str = "abba";
//    std::string str = "abcdba";
    std::string str = "ccbcabraabba";
    std::cout << Solution().getLongestPalindrome(str) << std::endl;
    return 0;
}