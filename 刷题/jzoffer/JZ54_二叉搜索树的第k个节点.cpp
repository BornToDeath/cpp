//
// Created by lixiaoqing on 2021/12/8.
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
     * @param proot TreeNode类
     * @param k int整型
     * @return int整型
     */
    int KthNode(TreeNode *proot, int k) {
        if (proot == nullptr) {
            return -1;
        }
        auto ret = KthNode(proot->left, k);
        if (ret != -1) {
            return ret;
        }

        ++index;
        if (index == k) {
            return proot->val;
        }

        ret = KthNode(proot->right, k);
        if (ret != -1) {
            return ret;
        }

        return -1;
    }

private:
    int index = 0;
};

int main() {
    auto root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution solution;
    std::cout << solution.KthNode(root, 4) << std::endl;
    return 0;
}