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
        /*
         * 方法1: 借助哈希表和 std::sort
         */
//        std::unordered_map<char, int> umap;
//        int pos = 0;
//        for (auto c: order) {
//            if (umap.count(c) == 0) {
//                umap[c] = pos++;
//            }
//        }
//        auto temp = words;
//        std::sort(temp.begin(), temp.end(), [&umap](const std::string &s1, const std::string &s2) {
//            int i = 0;
//            for (; i < s1.length() || i < s2.length(); ++i) {
//                auto n1 = i < s1.length() ? umap[s1.at(i)] : -1;
//                auto n2 = i < s2.length() ? umap[s2.at(i)] : -1;
//                if (n1 > n2) {
//                    return false;
//                } else if (n1 < n2) {
//                    return true;
//                }
//            }
//            return true;
//        });
//        for (int i = 0; i < words.size(); ++i) {
//            if (words.at(i) != temp.at(i)) {
//                return false;
//            }
//        }
//        return true;

        /*
         * 方法2: 按照 order 的字母下标，逐位对比每个单词的字母就好了
         * 时间复杂度 O(nm) , 其中 n 是 words 的长度, m 是单词的平均长度
         * 空间复杂度 O(C) , 其中 C 是字母表长度, 此为 26
         */
        std::unordered_map<char, int> hash;
        for (int i = 0; i < order.size(); ++i) {
            hash[order.at(i)] = i;
        }
        for (int i = 1; i < words.size(); ++i) {
            if (!compare(words.at(i - 1), words.at(i), hash)) {
                return false;
            }
        }
        return true;
    }

private:
    bool compare(const std::string &s1, const std::string &s2, const std::unordered_map<char, int> &hash) {
        for (int i = 0; i < s1.length() || i < s2.length(); ++i) {
            auto n1 = i < s1.length() ? hash.at(s1.at(i)) : -1;
            auto n2 = i < s2.length() ? hash.at(s2.at(i)) : -1;
            if (n1 < n2) {
                return true;
            } else if (n1 > n2) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::vector<std::string> words = {"hello", "leetcode"};
    std::string order = "hlabcdefgijkmnopqrstuvwxyz";

    words = {"zzz", "word", "world", "row", "aaa", "bbb", "ccc"};
    order = "worldabcefghijkmnpqstuvxyz";

    std::cout << Solution().isAlienSorted(words, order) << std::endl;
    return 0;
}