//
// Created by lixiaoqing on 2022/8/17.
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

#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        /**
         * 方法：二叉搜索树的中序遍历一定是升序序列，所以可以借鉴二分查找的思想
         * 时间复杂度 O(n) ，空间复杂度 O(logn)
         */
        return BST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *BST(vector<int> &nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        auto mid = left + ((right - left) >> 1);
        auto root = new TreeNode(nums[mid]);
        root->left = BST(nums, left, mid - 1);
        root->right = BST(nums, mid + 1, right);
        return root;
    }
};