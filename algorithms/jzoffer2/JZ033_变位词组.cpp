//
// Created by lixiaoqing on 2023/6/15.
//

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        /*
         * 方法1: 对字符串进行排序
         */
//        std::unordered_map<std::string, std::vector<std::string>> map;
//        for (const auto &s: strs) {
//            auto t = s;
//            std::sort(t.begin(), t.end());
//            map[t].emplace_back(s);
//        }
//        std::vector<std::vector<std::string>> ans;
//        for (const auto &pair: map) {
//            ans.emplace_back(pair.second);
//        }
//        return ans;

        /*
         * 方法2: 计数
         */
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (const auto &s: strs) {
            std::string t(26, '0');
            for (auto c: s) {
                ++t[c - 'a'];
            }
            map[t].emplace_back(s);
        }
        std::vector<std::vector<std::string>> ans;
        for (const auto &pair: map) {
            ans.emplace_back(pair.second);
        }
        return ans;
    }
};

int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
//    strs = {"a"};
    auto ans = Solution().groupAnagrams(strs);
    for (const auto &v: ans) {
        for (const auto &s: v) {
            std::cout << s << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}