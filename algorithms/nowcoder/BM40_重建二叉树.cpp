//
// Created by lixiaoqing on 2022/10/27.
//

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        return reconstruct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }

private:
    TreeNode *reconstruct(std::vector<int> &pre, int begin1, int end1, std::vector<int> &in, int begin2, int end2) {
        if (begin1 < 0 || end1 >= pre.size() || begin1 > end1) {
            return nullptr;
        }
        int pos = std::find(in.begin(), in.end(), pre[begin1]) - in.begin();
        auto root = new TreeNode(pre[begin1]);
        root->left = reconstruct(pre, begin1 + 1, begin1 + pos - begin2, in, begin2, pos - 1);
        root->right = reconstruct(pre, begin1 + pos - begin2 + 1, end1, in, pos + 1, end2);
        return root;
    }
};


int main() {
    std::vector<int> preOrder = {1, 2, 4, 7, 3, 5, 6, 8};
    std::vector<int> inOrder = {4, 7, 2, 1, 5, 3, 8, 6};
    auto root = Solution().reConstructBinaryTree(preOrder, inOrder);
    return 0;
}