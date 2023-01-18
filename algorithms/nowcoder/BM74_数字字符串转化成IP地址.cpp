//
// Created by lixiaoqing on 2022/5/21.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return string字符串vector
     */
    vector<string> restoreIpAddresses(string s) {
        /**
         * 方法1：递归
         */
//        if (s.empty() || s.length() < 4 || s.length() > 12) {
//            return {};
//        }
//        restore(s, "", 0);
//        return res;

        /**
         * 方法2：迭代
         */
        if (s.empty() || s.length() < 4 || s.length() > 12) {
            return {};
        }
        std::vector<std::string> res;
        int len = s.length();
        // 第一个点可能的位置
        for (int i = 1; i < 4 && i < len - 2; ++i) {
            // 第二个点可能的位置
            for (int j = i + 1; j < i + 4 && j < len - 1; ++j) {
                // 第三个点可能的位置
                for (int k = j + 1; k < j + 4 && k < len; ++k) {
                    if (len - k > 3) {
                        continue;
                    }
                    auto s1 = s.substr(0, i);
                    auto s2 = s.substr(i, j - i);
                    auto s3 = s.substr(j, k - j);
                    auto s4 = s.substr(k);
                    if (std::stoi(s1) > 255 || std::stoi(s2) > 255 || std::stoi(s3) > 255 || std::stoi(s4) > 255) {
                        continue;
                    }
                    if (s1.length() > 1 && s1[0] == '0' || s2.length() > 1 && s2[0] == '0' ||
                        s3.length() > 1 && s3[0] == '0' || s4.length() > 1 && s4[0] == '0') {
                        continue;
                    }
                    res.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
                }
            }
        }
        return res;
    }

private:
    void restore(string s, std::string ip, int count) {
        if (s.empty()) {
            if (count == 4) {
                ip.pop_back();
                res.emplace_back(ip);
            }
            return;
        }
        restore(s.substr(1), ip + s.substr(0, 1) + ".", count + 1);
        if (s.length() >= 2 && s[0] != '0') {
            restore(s.substr(2), ip + s.substr(0, 2) + ".", count + 1);
        }
        if (s.length() >= 3 && s[0] != '0' && std::stoi(s.substr(0, 3)) <= 255) {
            restore(s.substr(3), ip + s.substr(0, 3) + ".", count + 1);
        }
    }

private:
    std::vector<std::string> res;
};

int main() {
    std::string s = "1308758";
    auto res = Solution().restoreIpAddresses(s);
    for (auto ip: res) {
        std::cout << ip << std::endl;
    }
    return 0;
}