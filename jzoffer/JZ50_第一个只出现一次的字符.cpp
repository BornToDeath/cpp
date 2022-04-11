//
// Created by lixiaoqing on 2022/4/11.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        /**
         * 方法1：利用 std::map
         */
//        // 记录字符最后一次在字符串中出现的位置
//        std::map<char, int> dp;
//        for (int i = 0; i < str.length(); ++i) {
//            if (dp.find(str[i]) == dp.end()) {
//                // 如果没有出现过，记录位置
//                dp[str[i]] = i;
//            } else {
//                // 如果已经出现过，置为-1
//                dp[str[i]] = -1;
//            }
//        }
//        for (int i = 0; i < str.length(); ++i) {
//            if (dp[str[i]] != -1) {
//                return i;
//            }
//        }
//        return -1;

        /**
         * 方法2：利用 std::vector
         */
        std::vector<int> dp(64, 0);
        for (auto ch: str) {
            dp[ch - 'A']++;
        }

        for (int i = 0; i < str.length(); ++i) {
            if (dp[str[i] - 'A'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    const std::string str = "lRYdsgSqrlOakFmgyrlOXPqMAdOImyuUvINIWjKlctBYahuImDGXEMIBLvpIlLezXeOMzIVeqnYvH";
    std::cout << Solution().FirstNotRepeatingChar(str) << std::endl;
    return 0;
}