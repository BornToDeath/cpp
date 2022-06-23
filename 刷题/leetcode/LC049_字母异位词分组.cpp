//
// Created by lixiaoqing on 2022/6/22.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        /**
         * 方法1：对每个字符串进行排序，互为异位词的字符串排序之后是相同的。
         */
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (auto &str: strs) {
            auto temp = str;
            std::sort(temp.begin(), temp.end());
            map[temp].push_back(str);
        }
        std::vector<std::vector<std::string>> ans;
        for (auto &ele : map) {
            ans.emplace_back(ele.second);
        }
        return ans;

        /**
         * 方法2：计数
         */
//        std::unordered_map<std::string, std::vector<std::string>> map;
//        for (auto &str: strs) {
//            std::string temp(26, '0');
//            for (auto ch: str) {
//                ++temp[ch - 'a'];
//            }
//            map[temp].push_back(str);
//        }
//        std::vector<std::vector<std::string>> ans;
//        for (auto &pair: map) {
//            ans.emplace_back(pair.second);
//        }
//        return ans;
    }
};

int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans = Solution().groupAnagrams(strs);
    for (auto &ele: ans) {
        for (auto &str: ele) {
            std::cout << str << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}