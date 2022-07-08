//
// Created by lixiaoqing on 2022/7/8.
//

#include <unordered_map>
#include <string>

using namespace std;

class Trie {
private:
    class TrieNode {
    public:
        std::unordered_map<char, TrieNode *> children;
        bool isEnd{false};
    };

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        auto node = root;
        for (auto ch: word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        auto node = searchPrefix(word);
        return node && node->isEnd;
    }

    bool startsWith(string prefix) {
        auto node = searchPrefix(prefix);
        return node != nullptr;
    }

private:
    TrieNode *searchPrefix(const std::string_view prefix) {
        auto node = root;
        for (auto ch: prefix) {
            if (!node->children.count(ch)) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

private:
    TrieNode *root{nullptr};
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */