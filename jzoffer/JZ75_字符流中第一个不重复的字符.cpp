//
// Created by lixiaoqing on 2022/4/15.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>

/**
 * 方法1
 */
class Solution {
public:
    //Insert one char from stringstream
    void Insert(char ch) {
        auto it = std::find(dp.begin(), dp.end(), ch);
        if (it == dp.end()) {
            if (_set.find(ch) == _set.end()) {
                _set.insert(ch);
                dp.push_back(ch);
            }
            if (dp.size() > 1 && dp[0] == '#') {
                dp.erase(dp.begin());
            }
        } else {
            dp.erase(it);
            if (dp.empty()) {
                dp.push_back('#');
            }
        }
    }

    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        return dp.front();
    }

private:
    // 按顺序记录只出现一次的字符
    std::vector<char> dp;
    // 记录从始至终只出现一次的字符
    std::set<char> _set;
};

/**
 * 方法2
 */
class Solution2 {
public:
    //Insert one char from stringstream
    void Insert(char ch) {
        str.push_back(ch);
        ++dp[ch];
    }

    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for (auto ch: str) {
            if (dp[ch] == 1) {
                return ch;
            }
        }
        return '#';
    }

private:
    std::string str;
    int dp[256]{};
};

int main() {
    Solution2 solution;
    const std::string str = "googgggggleel";
    for (const auto ch: str) {
        solution.Insert(ch);
        std::cout << solution.FirstAppearingOnce();
    }
    std::cout << std::endl;

    if (-1) {
        int num = 1;
    } else {
        int num = 1;
    }

    return 0;
}