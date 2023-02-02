//
// Created by lixiaoqing on 2023/2/2.
//

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        /**
         * 方法1：整数枚举
         * 时间复杂度 O(1) ；空间复杂度 O(1)
         */
//        std::vector<std::string> ans;
//        for (auto i = 0; i < 12; ++i) {
//            for (auto j = 0; j < 60; ++j) {
//                if (std::bitset<4>(i).count() + std::bitset<6>(j).count() == turnedOn) {
//                    ans.emplace_back(std::to_string(i) + ":" + (j < 10 ? "0" : "") + std::to_string(j));
//                }
//            }
//        }
//        return ans;

        /**
         * 方法2：二进制枚举：高4位为小时，低6位为分钟
         * 时间复杂度 O(1) ；空间复杂度 O(1)
         */
        std::vector<std::string> ans;
        for (int i = 0; i < 1024; ++i) {
            // 取时、分
            int h = i >> 6, m = i & 63;
            if (h < 12 && m < 60 && std::bitset<10>(i).count() == turnedOn) {
                ans.emplace_back(std::to_string(h) + ":" + (m < 10 ? "0" : "") + std::to_string(m));
            }
        }
        return ans;
    }
};

int main() {
    auto ans = Solution().readBinaryWatch(1);
    for (auto &s: ans) {
        std::cout << s << std::endl;
    }
    return 0;
}