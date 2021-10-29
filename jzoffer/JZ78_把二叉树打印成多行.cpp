//
// Created by lixiaoqing on 2021/10/29.
//

#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"

using namespace std;

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
    vector<vector<int>> Print(TreeNode *pRoot) {
        vector<vector<int>> res;
        if (pRoot == nullptr) {
            return res;
        }

        vector<int> nums;
        queue<TreeNode *> queue;
        queue.push(pRoot);
        while (!queue.empty()) {
            int count = queue.size();
            for (int i = 0; i < count; ++i) {
                auto node = queue.front();
                queue.pop();
                nums.push_back(node->val);
                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }
            res.push_back(nums);
            nums.clear();
        }
        return res;
    }
};

int main() {
    return 0;
}