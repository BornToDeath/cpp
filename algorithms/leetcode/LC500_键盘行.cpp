//
// Created by lixiaoqing on 2023/2/28.
//

#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        /**
         * 方法1：先将所有字母存至哈希表中，然后遍历 words
         */
//        if (words.empty()) {
//            return {};
//        }
//        const std::string s1 = "qwertyuiopQWERTYUIOP";
//        const std::string s2 = "asdfghjklASDFGHJKL";
//        const std::string s3 = "zxcvbnmZXCVBNM";
//        _set1 = std::unordered_set<char>(s1.begin(), s1.end());
//        _set2 = std::unordered_set<char>(s2.begin(), s2.end());
//        _set3 = std::unordered_set<char>(s3.begin(), s3.end());
//        std::vector<std::string> ans;
//        for (const std::string &word: words) {
//            if (checkWord(word)) {
//                ans.emplace_back(word);
//            }
//        }
//        return ans;

        /**
         * 方法2：将键盘上每个字母标记上其所在键盘上的行号，然后检测字符串中所有字母对应的行号是否相同
         *   时间复杂度 O(L), L 表示 words 中所有字符串长度之和
         *   空间复杂度 O(C), C 表示英文字母的个数，在此为 26
         */
        const std::string alphabet = "23321222122233111121131313";
        std::vector<std::string> ans;
        for (auto &word: words) {
            char line = alphabet[std::tolower(word.front()) - 'a'];
            bool flag = std::all_of(word.begin(), word.end(), [&alphabet, line](char c) {
                return alphabet[std::tolower(c) - 'a'] == line;
            });
            if (flag) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }

private:
    bool checkWord(const std::string &word) {
        if (word.empty()) {
            return false;
        }
        auto check = [](const std::unordered_set<char> &_set, const std::string &word) -> bool {
            return std::all_of(word.begin(), word.end(), [&_set](char c) { return _set.count(c) == 1; });
        };
        return check(_set1, word) || check(_set2, word) || check(_set3, word);
    }

private:
    std::unordered_set<char> _set1, _set2, _set3;
};

int main() {
    std::vector<std::string> words = {"Hello", "Alaska", "Dad", "Peace"};
    auto ans = Solution().findWords(words);
    for (auto &s: ans) {
        std::cout << s << std::endl;
    }

    return 0;
}