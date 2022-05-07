//
// Created by lixiaoqing on 2022/5/7.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @param pattern string字符串
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        /**
         * 方法：动态规划。时间复杂度 O(mn), 空间复杂度 O(mn)
         * 参考：https://mp.weixin.qq.com/s?__biz=MzA3NTUwNzk0Mw==&mid=2729167089&idx=1&sn=afe53e0b1fdbf587da1de63805cb40ac&chksm=b83019798f47906f040e43cda8ab13bd6b5945956976000350fc7e3153ffbff03426abd59106#rd
         */
        auto rows = str.length() + 1;
        auto cols = pattern.length() + 1;
        // dp[i][j] 表示第 str 前 i 个字符和 pattern 前 j 个字符是否匹配
        std::vector<std::vector<bool>> dp(rows, std::vector<bool>(cols, false));
        // 如果 str 和 pattern 都是空的则认为匹配
        dp[0][0] = true;
        // dp 第一行：即 str 为空时
        for (int i = 2; i < cols; ++i) {
            if (pattern[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }
        // 遍历 str 和 pattern
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                // 如果 pattern 第 j 个字符是 *
                if (j >= 2 && pattern[j - 1] == '*') {
                    // 如果 pattern 第 j-1 个字符是 . (组成 .*) ，或者第 j-1 个字符与 str 第 i 个字符相等
                    // 比如: (abc, ab.*), (abc, abc.*), (abc, abcc*)
                    if (pattern[j - 2] == '.' || pattern[j - 2] == str[i - 1]) {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 2];
                    }
                } else if (pattern[j - 1] == '.' || pattern[j - 1] == str[i - 1]) {
                    // 否则，如果 pattern 第 j 个字符是 . 或者与 str 的第 i 个字符相同
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution().match("a", ".*") << std::endl;
    return 0;
}
