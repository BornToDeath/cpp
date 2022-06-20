//
// Created by lixiaoqing on 2022/6/17.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        std::unordered_map<char, std::string> umap = {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };
        std::vector<std::string> res;
        std::string ele;
        combinations(digits, ele, res, umap);
        return res;
    }

private:
    // dfs
    void combinations(const std::string &digits, std::string &letter, std::vector<std::string> &res,
                      std::unordered_map<char, std::string> MAP) {
        if (letter.size() == digits.size()) {
            res.emplace_back(letter);
            return;
        }
        int size = letter.size();
        for (auto ch: MAP[digits[size]]) {
            letter.push_back(ch);
            combinations(digits, letter, res, MAP);
            letter.pop_back();
        }
    }
};

int main() {
    std::string digits = "23";
    auto res = Solution().letterCombinations(digits);
    for (auto &str: res) {
        std::cout << str << std::endl;
    }
    return 0;
}