//
// Created by lixiaoqing on 2022/3/9.
//

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        return realReconstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }

private:
    TreeNode *realReconstructBinaryTree(vector<int> pre, int start1, int end1, vector<int> vin, int start2, int end2) {
        if (start1 > end1 || start2 > end2 || start1 < 0 || end1 >= pre.size() || start2 < 0 || end2 >= vin.size()) {
            return nullptr;
        }
        const int value = pre[start1];
        auto root = new TreeNode(value);
        int index = 0;
        for (int offset = start2; offset <= end2; ++offset) {
            if (value == vin[offset]) {
                index = offset - start2;
                break;
            }
        }
        root->left = realReconstructBinaryTree(pre, start1 + 1, start1 + index, vin, start2, start2 + index - 1);
        root->right = realReconstructBinaryTree(pre, start1 + index + 1, end1, vin, start2 + index + 1, end2);
        return root;
    }
};

int main() {
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
//    auto index = std::find(pre.begin(), pre.end(), 7) - pre.begin();
//    std::cout << index << std::endl;

    Solution solution;
    auto root = solution.reConstructBinaryTree(pre, vin);
    return 0;
}