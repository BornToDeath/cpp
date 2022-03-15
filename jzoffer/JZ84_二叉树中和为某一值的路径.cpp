//
// Created by lixiaoqing on 2022/3/15.
//

#include <iostream>
#include "TreeNode.h"

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return int整型
     */
    int FindPath(TreeNode *root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        realFindPath(root, sum);
        if (root->left) {
            FindPath(root->left, sum);
        }
        if (root->right) {
            FindPath(root->right, sum);
        }
        return count;
    }

private:
    void realFindPath(TreeNode *root, int sum) {
        if (root == nullptr) {
            return;
        }
        if (root->val == sum) {
            ++count;
        }
        realFindPath(root->left, sum - root->val);
        realFindPath(root->right, sum - root->val);
    }

private:
    int count = 0;
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(-1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    std::cout << solution.FindPath(root, 6) << std::endl;
}
