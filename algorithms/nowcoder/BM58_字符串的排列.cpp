//
// Created by lixiaoqing on 2022/10/27.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        /**
         * 方法1：使用 std::vector 存储数据，不AC，时间超限
         * 时间复杂度 O(n!) ，空间复杂度 O(n!)
         */
//        if (str.empty()) {
//            return {};
//        }
//        std::vector<std::string> strs;
//        permutation(str, 0, strs);
//        return strs;

        /**
         * 方法2：使用 std::set 存储数据，AC
         * 时间复杂度 O(n!) ，空间复杂度 O(n!)
         */
        if (str.empty()) {
            return {};
        }
        std::set<std::string> _sets;
        permutation(str, 0, _sets);
        std::vector<std::string> strs(_sets.begin(), _sets.end());
        return strs;
    }

private:

    void permutation(std::string &str, int pos, std::set<std::string> &_sets) {
        if (pos == str.length() - 1) {
            _sets.insert(str);
            return;
        }
        for (int i = pos; i < str.length(); ++i) {
            swap(str[i], str[pos]);
            permutation(str, pos + 1, _sets);
            swap(str[i], str[pos]);
        }
    }

    void permutation(std::string &str, int pos, std::vector<std::string> &strs) {
        if (pos == str.length() - 1) {
            if (std::find(strs.begin(), strs.end(), str) == strs.end()) {
                std::cout << str << std::endl;
                strs.emplace_back(str);
            }
            return;
        }
        for (int i = pos; i < str.length(); ++i) {
            swap(str[i], str[pos]);
            permutation(str, pos + 1, strs);
            swap(str[i], str[pos]);
        }
    }
};

int main() {
    auto ans = Solution().Permutation("qwertyuio");
    for (auto &s: ans) {
        std::cout << s << ", ";
    }
    std::cout << std::endl;
    return 0;
}