//
// Created by lixiaoqing on 2023/4/26.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        std::unordered_map<char, int> umap;
        int pos = 0;
        for (auto c: order) {
            if (umap.count(c) == 0) {
                umap[c] = pos++;
            }
        }
        auto temp = words;
        std::sort(temp.begin(), temp.end(), [&umap](const std::string &s1, const std::string &s2) {
            int i = 0;
            for (; i < s1.length() && i < s2.length(); ++i) {
                auto n1 = umap[s1.at(i)], n2 = umap[s2.at(i)];
                if (umap[s1.at(i)] > umap[s2.at(i)]) {
                    return false;
                }
            }
            if (i < s1.length() && i == s2.length()) {
                return false;
            }
            return true;
        });
        for (int i = 0; i < words.size(); ++i) {
            if (words.at(i) != temp.at(i)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::vector<std::string> words = {"hello", "leetcode"};
    std::string order = "hlabcdefgijkmnopqrstuvwxyz";

    words = {"word","world","row"};
    order = "worldabcefghijkmnpqstuvxyz";

    std::cout << Solution().isAlienSorted(words, order) << std::endl;
    return 0;
}