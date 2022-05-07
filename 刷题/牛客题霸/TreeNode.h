//
// Created by lixiaoqing on 2022/5/7.
//

#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
public:
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

#endif //TREENODE_H
