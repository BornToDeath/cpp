//
// Created by lixiaoqing on 2022/5/7.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型vector
     */
    vector<int> postorderTraversal(TreeNode *root) {
        std::vector<int> v;
        postorder(root, v);
        return v;
    }

private:
    void postorder(TreeNode *root, std::vector<int> &v) {
        if (root) {
            postorder(root->left, v);
            postorder(root->right, v);
            v.emplace_back(root->val);
        }
    }
};