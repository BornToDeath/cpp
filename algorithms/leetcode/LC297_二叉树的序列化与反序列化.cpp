//
// Created by lixiaoqing on 2023/5/5.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <string>
#include <queue>
#include "TreeNode.h"

using std::string;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        std::string ans;
        serialize(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int pos = 0;
        return deserialize(data, pos);
    }

private:

    void serialize(TreeNode *root, std::string &str) {
        if (root == nullptr) {
            str.append("#,");
            return;
        }
        str.append(std::to_string(root->val)).push_back(',');
        serialize(root->left, str);
        serialize(root->right, str);
    }

    TreeNode *deserialize(const std::string &data, int &pos) {
        if (pos >= data.length()) {
            return nullptr;
        }
        if (data.at(pos) == '#') {
            pos += 2;
            return nullptr;
        }
        int val = 0;
        int flag = 1;
        if (pos < data.length() && data.at(pos) == '-') {  // 可能存在负数
            flag = -1;
            ++pos;
        }
        while (pos < data.length() && data.at(pos) != ',') {
            val = val * 10 + data.at(pos) - '0';
            ++pos;
        }
        ++pos;
        auto node = new TreeNode(val * flag);
        node->left = deserialize(data, pos);
        node->right = deserialize(data, pos);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    auto str = Codec().serialize(root);
    std::cout << str << std::endl;
    auto newRoot = Codec().deserialize(str);
    return 0;
}