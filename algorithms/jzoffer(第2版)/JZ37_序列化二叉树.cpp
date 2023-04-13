//
// Created by lixiaoqing on 2023/4/13.
//

#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include "TreeNode.h"

using std::string;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        // 先序遍历
        if (root == nullptr) {
            return "#,";
        }
        std::string ans(std::to_string(root->val) + ",");
        ans.append(serialize(root->left));
        ans.append(serialize(root->right));
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        /*
         * 方式1: 先将所有的节点值保存到 vector 中
         */
//        std::vector<std::string> v;
//        std::istringstream iss(data);
//        std::string temp;
//        while (getline(iss, temp, ',')) {
//            if (!temp.empty()) {
//                v.emplace_back(temp);
//            }
//        }
//        int pos = -1;
//        return deserialize(v, pos);

        /*
         * 方式2: 直接操作 data
         */
        int pos = 0;
        return deserialize(data, pos);
    }

private:
    TreeNode *deserialize(const std::vector<std::string> &v, int &pos) {
        if (v[++pos] == "#") {
            return nullptr;
        }
        auto root = new TreeNode(std::stoi(v[pos]));
        root->left = deserialize(v, pos);
        root->right = deserialize(v, pos);
        return root;
    }

    TreeNode *deserialize(const std::string &data, int &pos) {
        if (pos >= data.length() || data[pos] == '#') {
            pos += 2;
            return nullptr;
        }
        // 可能存在负数
        int val = 0;
        bool positive = true;
        for (; pos < data.length() && data[pos] != ','; ++pos) {
            if (data[pos] == '-') {
                positive = false;
            } else {
                val = val * 10 + data[pos] - '0';
            }
        }
        if (!positive) {
            val *= -1;
        }
        ++pos;
        auto root = new TreeNode(val);
        root->left = deserialize(data, pos);
        root->right = deserialize(data, pos);
        return root;
    }
};

int main() {
//    auto root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->right->left = new TreeNode(4);
//    root->right->right = new TreeNode(5);
    auto root = new TreeNode(-1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    auto s = Codec().serialize(root);
    std::cout << s << std::endl;
    auto root2 = Codec().deserialize(s);
    return 0;
}