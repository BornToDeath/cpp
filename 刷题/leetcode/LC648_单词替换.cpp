//
// Created by lixiaoqing on 2022/7/7.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        /**
         * 方法1：逐个单词匹配
         */
//        if (sentence.empty() || dictionary.empty()) {
//            return sentence;
//        }
//        std::sort(dictionary.begin(), dictionary.end(), [](const std::string &s1, const std::string &s2) {
//            return s1.length() < s2.length();
//        });
//        std::unordered_map<int, std::string> map;
//        std::istringstream iss(sentence);
//        std::string word;
//        int pos = 0;
//        while (getline(iss, word, ' ')) {
//            if (!word.empty()) {
//                map[pos++] = word;
//            }
//        }
//        std::map<int, std::string> map2;
//        while (!map.empty()) {
//            auto ele = map.begin();
//            map2[ele->first] = ele->second;
//            for (auto &s: dictionary) {
//                if (ele->second.find(s) == 0) {
//                    map2[ele->first] = s;
//                    break;
//                }
//            }
//            map.erase(ele);
//        }
//        std::string ans;
//        for (auto ele: map2) {
//            ans.append(ele.second + ' ');
//        }
//        ans.pop_back();
//        return ans;

        /**
         * 方法2：字典树（又称前缀树）
         */
        // 构建字典树
        auto root = new TrieNode();
        for (auto &word: dictionary) {
            auto cur = root;
            for (auto ch: word) {
                if (!cur->children.count(ch)) {
                    cur->children[ch] = new TrieNode();
                }
                cur = cur->children[ch];
            }
            cur->isEnd = true;
        }
        // split
        auto words = split(sentence);
        // 字典树搜索
        for (auto &word: words) {
            auto cur = root;
            std::string temp;
            for (auto ch: word) {
                if (cur->isEnd) {
                    word = temp;
                    break;
                }
                if (!cur->children.count(ch)) {
                    break;
                }
                temp.push_back(ch);
                cur = cur->children[ch];
            }
        }
        // 组装返回值
        std::string ans;
        for (auto &word: words) {
            if (!word.empty()) {
                ans.append(word + ' ');
            }
        }
        ans.pop_back();
        return ans;
    }

private:
    std::vector<std::string> split(std::string_view sentence) {
        std::vector<std::string> words;
        int pos = 0;
        while ((pos = sentence.find_first_of(' ')) != std::string::npos) {
            auto word = sentence.substr(0, pos);
            if (!word.empty()) {
                words.emplace_back(word);
            }
            sentence = sentence.substr(pos + 1);
        }
        if (!sentence.empty()) {
            words.emplace_back(sentence);
        }
        return words;
    }

private:
    /**
     * 字典树节点定义
     */
    class TrieNode {
    public:
        std::unordered_map<char, TrieNode *> children;
        bool isEnd{false};  // 标识是否是叶子结点
    };
};

int main() {
//    std::vector<std::string> dic = {"a", "b", "c"};
//    std::string sentence = "aadsfasf absbs bbab cadsfafs";
    std::vector<std::string> dic = {"cat", "bat", "rat"};
    std::string sentence = "the cattle was rattled by the battery";
    std::cout << Solution().replaceWords(dic, sentence) << std::endl;
    return 0;
}