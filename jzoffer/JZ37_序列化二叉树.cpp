//
// Created by lixiaoqing on 2021/11/1.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include "TreeNode.h"

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

class Solution {
public:
    char *Serialize(TreeNode *root) {
        auto str = seriallize(root);
        auto ret = new char[str.length() + 1]();
        auto temp = ret;
        for (const auto c: str) {
            *temp++ = c;
        }
        *temp = '\0';
        return ret;
    }

    TreeNode *Deserialize(char *str) {
        std::vector<std::string> strs;

        // split
        std::istringstream iss(str);
        std::string temp;
        while (getline(iss, temp, ',')) {
            if (temp.empty()) {
                continue;
            }
            strs.emplace_back(temp);
        }

        return deserialize(strs);
    }

private:
    /**
     * 先序遍历
     * @param root
     * @return
     */
    std::string seriallize(TreeNode *root) {
        if (root == nullptr) {
            return "#,";
        }
        std::string str;
        str.append(std::to_string(root->val) + ",");
        str.append(seriallize(root->left));
        str.append(seriallize(root->right));
        return str;
    }

    /**
     * 根据先序遍历的结果重构二叉树
     * @param str
     * @return
     */
    TreeNode *deserialize(std::vector<std::string> &strs) {
        ++index;
        if (strs[index] == "#") {
            return nullptr;
        }
        auto node = new TreeNode(std::stoi(strs[index]));
        node->left = deserialize(strs);
        node->right = deserialize(strs);
        return node;
    }

private:
    int index = -1;
};

int main() {
//    auto root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->right->left = new TreeNode(4);
//    root->right->right = new TreeNode(5);

    auto root = new TreeNode(100);
    root->left = new TreeNode(50);
    root->left->right = new TreeNode(150);

    Solution solution;
    auto str = solution.Serialize(root);
    std::cout << str << std::endl;

    auto node = solution.Deserialize(str);
    return 0;
}