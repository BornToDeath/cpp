//
// Created by lixiaoqing on 2022/6/28.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <vector>
#include <climits>
#include "TreeNode.h"

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        /**
         * 方法1：
         */
//        std::vector<int> nums;
//        inOrder(root, nums);
//        for (int i = 0; i < nums.size() - 1; ++i) {
//            if (nums[i] >= nums[i + 1]) {
//                return false;
//            }
//        }
//        return true;

        /**
         * 方法2：
         */
        if (root == nullptr) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (root->val <= pre) {
            return false;
        }
        pre = root->val;
        return isValidBST(root->right);
    }

private:
    void inOrder(TreeNode *root, std::vector<int> &nums) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, nums);
        nums.emplace_back(root->val);
        inOrder(root->right, nums);
    }

private:
    long pre = LONG_MIN;
};

int main() {
    std::cout << INT_MIN << std::endl;
    return 0;
}