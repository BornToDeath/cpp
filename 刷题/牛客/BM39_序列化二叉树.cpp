//
// Created by lixiaoqing on 2022/10/26.
//

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

#include <iostream>
#include <string>
#include "TreeNode.h"

class Solution {
public:
    char *Serialize(TreeNode *root) {
        auto s = new std::string();
        serialize(root, *s);
        return const_cast<char *>(s->c_str());
    }

    TreeNode *Deserialize(char *str) {
        int pos = 0;
        return deserialize(str, pos);
    }

private:
    /**
     * 先序遍历
     * @param root
     * @return
     */
    void serialize(TreeNode *root, std::string &s) {
        if (root == nullptr) {
            s.append("#,");
            return;
        }
        s.append(std::to_string(root->val) + ',');
        serialize(root->left, s);
        serialize(root->right, s);
    }

    TreeNode *deserialize(const std::string &s, int &pos) {
        if (pos >= s.length()) {
            return nullptr;
        }
        if (s[pos] == '#') {
            pos += 2;
            return nullptr;
        }
        int val = 0;
        for (; pos < s.length() && s[pos] != ','; ++pos) {
            val = val * 10 + s[pos] - '0';
        }
        ++pos;
        auto head = new TreeNode(val);
        head->left = deserialize(s, pos);
        head->right = deserialize(s, pos);
        return head;
    }
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    auto s = Solution().Serialize(root);
    std::cout << s << std::endl;

    auto newRoot = Solution().Deserialize(s);
    return 0;
}