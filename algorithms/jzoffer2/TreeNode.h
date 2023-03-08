//
// Created by lixiaoqing on 2022/6/16.
//

#ifndef ALGORITHMS_TREENODE_H
#define ALGORITHMS_TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //ALGORITHMS_TREENODE_H
