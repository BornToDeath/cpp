//
// Created by lixiaoqing on 2023/1/9.
//

/**
 * 字符串分割
 * 鉴智机器人一面算法题
 */

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> SplitString(const std::string &s, const char &c) {
    if (s.empty()) {
        return {};
    }
    std::vector<std::string> ans;
    int pos = 0;
    while (pos < s.length()) {
        auto t = s.find(c, pos);
        if (t == std::string::npos) {
            auto ele = s.substr(pos);
            if (!ele.empty()) {
                ans.emplace_back(ele);
            }
            break;
        }
        auto ele = s.substr(pos, t - pos);
        if (!ele.empty()) {
            ans.emplace_back(ele);
        }
        pos = t + 1;
    }
    return ans;
}

int main() {
    std::string str = "    the   quick brown fox jumps over the lazy dog";
    char c = ' ';
    auto res = SplitString(str, c);
    std::cout << res.size() << std::endl;
    for (auto &s: res) {
        printf("[%s]\n", s.c_str());
    }
    return 0;
}