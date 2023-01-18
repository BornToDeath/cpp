//
// Created by lixiaoqing on 2022/5/31.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    /**
     *
     * @param num int整型vector
     * @return TreeNode类
     */
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return constructBST(num, 0, num.size() - 1);
    }

private:
    TreeNode *constructBST(std::vector<int> &num, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        // 每次将中间的值作为根节点
        auto mid = (right - left) / 2 + left;
        auto root = new TreeNode(num[mid]);
        root->left = constructBST(num, left, mid - 1);
        root->right = constructBST(num, mid + 1, right);
        return root;
    }
};