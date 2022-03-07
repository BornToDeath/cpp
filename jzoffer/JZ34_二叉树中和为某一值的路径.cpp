//
// Created by lixiaoqing on 2022/3/7.
//

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

void printArray(const std::vector<int> &nums) {
    for (const auto &num: nums) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
        if (root == nullptr) {
            return {};
        }
        realFindPath(root, expectNumber);
        return paths;
    }

private:
    void realFindPath(TreeNode *root, int value) {
        if (root == nullptr) {
            return;
        }
        path.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr && root->val == value) {
            paths.emplace_back(path);
        }
        realFindPath(root->left, value - root->val);
        realFindPath(root->right, value - root->val);
        path.pop_back();
    }

private:
    std::vector<std::vector<int>> paths;
    std::vector<int> path;
};

int main() {

    auto root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);

    int value = 22;

    Solution solution;
    auto paths = solution.FindPath(root, value);

    return 0;
}