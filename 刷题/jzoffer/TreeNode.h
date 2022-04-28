//
// Created by lixiaoqing on 2021/10/29.
//

#ifndef JZOFFER_TREENODE_H
#define JZOFFER_TREENODE_H

class TreeNode {

public:
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

#endif //JZOFFER_TREENODE_H
